#ifndef ETICARET_SERVISI_HPP
#define ETICARET_SERVISI_HPP

#include <memory>
#include <vector>
#include <string>
#include <map> 

#include "../repositories/depo.hpp"
#include "../entities/musteri.hpp"
#include "../entities/adres.hpp"
#include "../entities/kategori.hpp"
#include "../entities/urun.hpp"
#include "../entities/siparis.hpp"
#include "../entities/siparisKalemi.hpp"
#include "../entities/odeme.hpp"

class ETicaretServisi {
private:
    Depo<Musteri>& _musteriDepo;
    Depo<Adres>& _adresDepo;
    Depo<Kategori>& _kategoriDepo;
    Depo<Urun>& _urunDepo;
    Depo<Siparis>& _siparisDepo;
    Depo<SiparisKalemi>& _siparisKalemiDepo;
    Depo<Odeme>& _odemeDepo;

public:
    ETicaretServisi(
        Depo<Musteri>& musteriDepo, Depo<Adres>& adresDepo,
        Depo<Kategori>& kategoriDepo, Depo<Urun>& urunDepo,
        Depo<Siparis>& siparisDepo, Depo<SiparisKalemi>& siparisKalemiDepo,
        Depo<Odeme>& odemeDepo
    );

    ~ETicaretServisi() = default;

    // Müşteri ve Adres İşlemleri
    void musteriKaydet(const std::string& email, const std::string& ad_soyad, const std::string& telefon);
    void adresEkle(int musteri_id, const std::string& baslik, const std::string& il, 
                   const std::string& ilce, const std::string& mahalle, const std::string& detay, const std::string& posta_kodu);

    // Ürün ve Kategori İşlemleri
    void kategoriEkle(const std::string& ad, int ust_kategori_id = 0);
    void urunEkle(const std::string& ad, const std::string& aciklama, double fiyat, int stok, int kategori_id);
    void stokGuncelle(int urun_id, int yeni_stok);

    // Sipariş Süreci (Core Logic)
    int siparisOlustur(int musteri_id, int adres_id);
    void sipariseUrunEkle(int siparis_id, int urun_id, int miktar);
    void siparisOnayla(int siparis_id);
    void siparisIptalEt(int siparis_id);

    // Ödeme İşlemleri
    void odemeAl(int siparis_id, const std::string& yontem);

    // Raporlama ve Listeleme
    std::vector<std::shared_ptr<Siparis>> musteriSiparisGecmisi(int musteri_id);
    std::vector<std::shared_ptr<Urun>> kategoriyeGoreUrunler(int kategori_id);
    std::vector<std::shared_ptr<Urun>> enCokSatanUrunler(int limit);

    std::string gunlukSatisRaporu(const std::string& tarih);
};

#endif // ETICARET_SERVISI_HPP