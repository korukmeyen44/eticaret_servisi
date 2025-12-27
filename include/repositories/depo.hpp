#ifndef DEPO_HPP
#define DEPO_HPP

#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <string>

template <typename T>
class Depo {
public:
    using Ptr = std::shared_ptr<T>;
    using Elemanlar = std::vector<Ptr>;
    using AramaFonksiyonu = std::function<bool(const Ptr&)>;

private:
    Elemanlar _elemanlar;
    int _sonrakiId = 1;

public:
    // Ekleme yaparken nesnenin kopyasını oluşturur
    void ekle(const Ptr& eleman) {
        if (eleman == nullptr) throw std::invalid_argument("Depo: Null eleman");
        
        Ptr yeniEleman = std::make_shared<T>(*eleman); // Copy Constructor çağrılır
        
        if (yeniEleman->get_id() == 0) {
            yeniEleman->set_id(_sonrakiId++);
        } else if (yeniEleman->get_id() >= _sonrakiId) {
            _sonrakiId = yeniEleman->get_id() + 1;
        }
        
        _elemanlar.push_back(yeniEleman);
    }

    // İstenen ID'li elemanın kopyasını döner
    Ptr getir(int id) const {
        auto it = std::find_if(_elemanlar.begin(), _elemanlar.end(), [id](const Ptr& e) { return e->get_id() == id; });
        if (it != _elemanlar.end()) return std::make_shared<T>(**it);
        throw std::runtime_error("Depo: Kayit bulunamadi ID: " + std::to_string(id));
    }

    // Kriterlere uyanların kopyalarını döner
    Elemanlar ara(AramaFonksiyonu kriter) const {
        Elemanlar sonuc;
        for (const auto& eleman : _elemanlar) {
            if (kriter(eleman)) {
                sonuc.push_back(std::make_shared<T>(*eleman));
            }
        }
        return sonuc;
    }

    // ID eşleşen kaydı yenisiyle değiştirir
    void guncelle(const Ptr& yeniEleman) {
        int id = yeniEleman->get_id();
        auto it = std::find_if(_elemanlar.begin(), _elemanlar.end(), [id](const Ptr& e) { return e->get_id() == id; });
        
        if (it != _elemanlar.end()) {
            *it = std::make_shared<T>(*yeniEleman);
        } else {
            throw std::runtime_error("Guncellenecek kayit yok ID: " + std::to_string(id));
        }
    }

    void sil(int id) {
        auto it = std::remove_if(_elemanlar.begin(), _elemanlar.end(), [id](const Ptr& e) { return e->get_id() == id; });
        if (it != _elemanlar.end()) {
            _elemanlar.erase(it, _elemanlar.end());
        } else {
            throw std::runtime_error("Silinecek kayit yok ID: " + std::to_string(id));
        }
    }

    Elemanlar tumunu() const {
        Elemanlar k; 
        k.reserve(_elemanlar.size());
        for (const auto& e : _elemanlar) k.push_back(std::make_shared<T>(*e));
        return k;
    }

    size_t boyut() const { return _elemanlar.size(); }
    
    // Iterator destekleri
    auto begin() { return _elemanlar.begin(); }
    auto begin() const { return _elemanlar.begin(); }
    auto end() { return _elemanlar.end(); }
    auto end() const { return _elemanlar.end(); }
};

#endif // DEPO_HPP