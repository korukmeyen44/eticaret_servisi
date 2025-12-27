#include "eticaretServisi.hpp"
#include "../utils/TarihUtils.hpp"

#include <stdexcept>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>

// Kurucu Metod: Depo referanslarını başlatır
ETicaretServisi::ETicaretServisi(
    Depo<Musteri>& musteriDepo, Depo<Adres>& adresDepo,
    Depo<Kategori>& kategoriDepo, Depo<Urun>& urunDepo,
    Depo<Siparis>& siparisDepo, Depo<SiparisKalemi>& siparisKalemiDepo,
    Depo<Odeme>& odemeDepo
) : _musteriDepo(musteriDepo), _adresDepo(adresDepo),
    _kategoriDepo(kategoriDepo), _urunDepo(urunDepo),
    _siparisDepo(siparisDepo), _siparisKalemiDepo(siparisKalemiDepo),
    _odemeDepo(odemeDepo)
{
}

void ETicaretServisi::musteriKaydet(const std::string& email, const std::string& ad_soyad, const std::string& telefon) {
    auto yeniMusteri = std::make_shared<Musteri>(0, email, ad_soyad, telefon, TarihUtils::bugunTarihi());
    _musteriDepo.ekle(yeniMusteri);
}

void ETicaretServisi::adresEkle(int musteri_id, const std::string& baslik, const std::string& il, 
               const std::string& ilce, const std::string& mahalle, const std::string& detay, const std::string& posta_kodu) {
    auto yeniAdres = std::make_shared<Adres>(0, musteri_id, baslik, il, ilce, mahalle, detay, posta_kodu);
    _adresDepo.ekle(yeniAdres);
}

void ETicaretServisi::kategoriEkle(const std::string& ad, int ust_kategori_id) {
    auto yeniKategori = std::make_shared<Kategori>(0, ad, ust_kategori_id);
    _kategoriDepo.ekle(yeniKategori);
}

void ETicaretServisi::urunEkle(const std::string& ad, const std::string& aciklama, double fiyat, int stok, int kategori_id) {
    auto yeniUrun = std::make_shared<Urun>(0, ad, aciklama, fiyat, stok, kategori_id);
    _urunDepo.ekle(yeniUrun);
}

int ETicaretServisi::siparisOlustur(int musteri_id, int adres_id) {
    auto yeniSiparis = std::make_shared<Siparis>(0, musteri_id, adres_id, TarihUtils::bugunTarihi(), "Bekliyor", 0.0);
    _siparisDepo.ekle(yeniSiparis);

    auto siparisler = _siparisDepo.ara([musteri_id](const std::shared_ptr<Siparis>& s) {
        return s->get_musteri_id() == musteri_id;
    });

    if (!siparisler.empty()) {
        return siparisler.back()->get_id();
    }
    return 0;
}

void ETicaretServisi::sipariseUrunEkle(int siparis_id, int urun_id, int miktar) {
    auto urun = _urunDepo.getir(urun_id);
    auto siparis = _siparisDepo.getir(siparis_id);

    if (urun->get_stok() < miktar) {
        throw std::runtime_error("Stok yetersiz! Urun: " + urun->get_ad());
    }

    // Stok düş
    urun->set_stok(urun->get_stok() - miktar);
    _urunDepo.guncelle(urun);

    // Kalem ekle
    auto kalem = std::make_shared<SiparisKalemi>(0, siparis_id, urun_id, miktar, urun->get_fiyat());
    _siparisKalemiDepo.ekle(kalem);

    // Sipariş toplamını güncelle
    double kalemTutari = urun->get_fiyat() * miktar;
    siparis->set_toplam_tutar(siparis->get_toplam_tutar() + kalemTutari);
    _siparisDepo.guncelle(siparis);
}

void ETicaretServisi::siparisOnayla(int siparis_id) {
    auto siparis = _siparisDepo.getir(siparis_id);
    siparis->set_durum("Onaylandı");
    _siparisDepo.guncelle(siparis);
}

void ETicaretServisi::siparisIptalEt(int siparis_id) {
    auto siparis = _siparisDepo.getir(siparis_id);
    siparis->set_durum("İptal Edildi");
    _siparisDepo.guncelle(siparis);
}

void ETicaretServisi::odemeAl(int siparis_id, const std::string& yontem) {
    auto siparis = _siparisDepo.getir(siparis_id);
    
    // Tutar siparişin kendisinden alınır
    double tutar = siparis->get_toplam_tutar();

    auto odeme = std::make_shared<Odeme>(0, siparis_id, yontem, tutar, TarihUtils::bugunTarihi(), "Tamamlandı");
    _odemeDepo.ekle(odeme);

    siparisOnayla(siparis_id);
}

void ETicaretServisi::stokGuncelle(int urun_id, int yeni_stok) {
    auto urun = _urunDepo.getir(urun_id);
    urun->set_stok(yeni_stok);
    _urunDepo.guncelle(urun);
}

std::vector<std::shared_ptr<Siparis>> ETicaretServisi::musteriSiparisGecmisi(int musteri_id) {
    return _siparisDepo.ara([musteri_id](const std::shared_ptr<Siparis>& s) {
        return s->get_musteri_id() == musteri_id;
    });
}

std::vector<std::shared_ptr<Urun>> ETicaretServisi::kategoriyeGoreUrunler(int kategori_id) {
    return _urunDepo.ara([kategori_id](const std::shared_ptr<Urun>& u) {
        return u->get_kategori_id() == kategori_id;
    });
}

std::vector<std::shared_ptr<Urun>> ETicaretServisi::enCokSatanUrunler(int limit) {
    auto kalemler = _siparisKalemiDepo.tumunu();
    std::map<int, int> satisSayilari;
    
    for (const auto& kalem : kalemler) {
        satisSayilari[kalem->get_urun_id()] += kalem->get_miktar();
    }

    std::vector<std::pair<int, int>> siraliListe(satisSayilari.begin(), satisSayilari.end());

    std::sort(siraliListe.begin(), siraliListe.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second; 
        }
    );

    std::vector<std::shared_ptr<Urun>> sonuc;
    int sayac = 0;
    for (const auto& item : siraliListe) {
        if (sayac >= limit) break;
        try {
            sonuc.push_back(_urunDepo.getir(item.first));
            sayac++;
        } catch (...) {
            continue;
        }
    }
    return sonuc;
}

std::string ETicaretServisi::gunlukSatisRaporu(const std::string& tarih) {
    std::stringstream ss;
    ss << "--- " << tarih << " Satis Raporu ---\n";
    
    auto siparisler = _siparisDepo.ara([tarih](const std::shared_ptr<Siparis>& s) {
        // Sadece belirtilen tarihteki ve Onaylanan siparisleri topla
        return s->get_tarih() == tarih && s->get_durum() == "Onaylandı";
    });

    double gunlukCiro = 0.0;
    int siparisSayisi = 0;

    for (const auto& siparis : siparisler) {
        gunlukCiro += siparis->get_toplam_tutar();
        siparisSayisi++;
        ss << "SIPARIS ID: " << siparis->get_id() << " - Tutar: " << siparis->get_toplam_tutar() << " TL\n";
    }

    ss << "--------------------------------\n";
    ss << "Toplam Ciro: " << gunlukCiro << " TL\n";
    ss << "Toplam Satis Adedi: " << siparisSayisi << "\n";

    return ss.str();
}