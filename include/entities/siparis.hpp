#ifndef SIPARIS_HPP
#define SIPARIS_HPP

#include <string>

class Siparis {
private:
    int id;
    int musteri_id;
    int adres_id;
    std::string tarih;
    std::string durum; // Bekliyor, Onaylandı, Kargoda, Teslim, İptal
    double toplam_tutar;

public:
    // Varsayılan ilklendirici
    Siparis();

    // Parametreli ilklendirici
    Siparis(int id, int musteri_id, int adres_id, const std::string& tarih,
            const std::string& durum, double toplam_tutar = 0.0);

    // Kopya ilklendirici
    Siparis(const Siparis& other);

    // Sonlandırıcı
    ~Siparis();

    // Getterlar
    int get_id() const;
    int get_musteri_id() const;
    int get_adres_id() const;
    std::string get_tarih() const;
    std::string get_durum() const;
    double get_toplam_tutar() const;

    // Setterlar
    void set_id(int id);
    void set_durum(const std::string& yeni_durum); // Bekliyor -> Onaylandı değişimi için
    void set_toplam_tutar(double yeni_tutar);      // Sepete ürün eklendikçe artması için
};

#endif // SIPARIS_HPP