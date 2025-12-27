#include <iostream>
#include <memory>
#include <vector>

#include "repositories/depo.hpp"
#include "entities/musteri.hpp"        
#include "entities/adres.hpp"
#include "entities/kategori.hpp"
#include "entities/urun.hpp"
#include "entities/siparis.hpp"
#include "entities/siparisKalemi.hpp"
#include "entities/odeme.hpp"
#include "services/eticaretServisi.hpp" 
#include "utils/TarihUtils.hpp"

using namespace std;

int main() {
    cout << "E-TICARET SIPARIS SISTEMI" << endl;
    cout << "Cok Katmanli Mimari Projesi" << endl;
    cout << "=================================" << endl << endl;

    // 1. Depoları (Repositories) Oluştur
    cout << "[1] Depolar olusturuluyor..." << endl;
    Depo<Musteri> musteriDepo;
    Depo<Adres> adresDepo;
    Depo<Kategori> kategoriDepo;
    Depo<Urun> urunDepo;
    Depo<Siparis> siparisDepo;
    Depo<SiparisKalemi> siparisKalemiDepo;
    Depo<Odeme> odemeDepo;

    // 2. Servisi (Business Logic) Oluştur
    cout << "[2] Servis olusturuluyor..." << endl;
    // Dependency Injection (Bağımlılık Enjeksiyonu)
    ETicaretServisi eticaret(
        musteriDepo, adresDepo, kategoriDepo, urunDepo,
        siparisDepo, siparisKalemiDepo, odemeDepo
    );

    // 3. Örnek Veri Yükle (Seed Data)
    cout << "[3] Ornek veriler yukleniyor..." << endl;

    // Kategoriler
    auto kat1 = make_shared<Kategori>(0, "Elektronik", 0);
    auto kat2 = make_shared<Kategori>(0, "Telefon", 1);
    auto kat3 = make_shared<Kategori>(0, "Bilgisayar", 1);
    kategoriDepo.ekle(kat1);
    kategoriDepo.ekle(kat2);
    kategoriDepo.ekle(kat3);

    // Ürünler
    auto urun1 = make_shared<Urun>(0, "iPhone 15", "Apple akilli telefon", 50000.0, 10, 2);
    auto urun2 = make_shared<Urun>(0, "MacBook Pro", "M3 islemcili laptop", 80000.0, 5, 3);
    auto urun3 = make_shared<Urun>(0, "Nokia3310", "Nokia cok akilli telefon", 400.0, 15, 2);
    urunDepo.ekle(urun1);
    urunDepo.ekle(urun2);
    urunDepo.ekle(urun3);

    // Müşteriler
    auto musteri1 = make_shared<Musteri>(0, "atagunpc44@gmail.com", "Atagün Körükmez", "444-444-4444", TarihUtils::bugunTarihi());
    auto musteri2 = make_shared<Musteri>(0, "abcde@mail.com", "Gizli Kullanici", "555-555-5555", TarihUtils::bugunTarihi());
    musteriDepo.ekle(musteri1);
    musteriDepo.ekle(musteri2);

    // Adresler
    auto adres1 = make_shared<Adres>(0, 1, "Ev", "Bursa", "Nilüfer", "Beşevler", "No:5 D:2", "16000");
    adresDepo.ekle(adres1);

    cout << "    -> Veriler yuklendi." << endl << endl;

    // 4. Servis İşlemlerini Test Et
    cout << "[4] Servis islemleri test ediliyor..." << endl << endl;

    try {
        // A. Sipariş Başlatma
        cout << "--- A. Siparis Olusturma ---" << endl;
        int siparis_id = eticaret.siparisOlustur(1, 1); 
        cout << "    -> Yeni Siparis ID: " << siparis_id << " olusturuldu." << endl;

        // B. Sepete Ürün Ekleme
        cout << "\n--- B. Sepete Urun Ekleme ---" << endl;
        eticaret.sipariseUrunEkle(siparis_id, 1, 2); 
        eticaret.sipariseUrunEkle(siparis_id, 2, 1);
        
        // C. Siparişi Onaylama ve Ödeme
        cout << "\n--- C. Odeme Alma ---" << endl;
        eticaret.odemeAl(siparis_id, "Kredi Karti");

        // D. Raporlama Testleri
        cout << "\n--- D. Raporlar ---" << endl;
        
        cout << "1. Ahmet'in Siparis Gecmisi:" << endl;
        auto gecmis = eticaret.musteriSiparisGecmisi(1);
        for(const auto& s : gecmis) {
            cout << "   - Siparis ID: " << s->get_id() 
                 << " Durum: " << s->get_durum() 
                 << " Tutar: " << s->get_toplam_tutar() << " TL" << endl;
        }

        cout << "\n2. Telefon Kategorisindeki Urunler:" << endl;
        auto telefonlar = eticaret.kategoriyeGoreUrunler(2);
        for(const auto& u : telefonlar) {
            cout << "   - " << u->get_ad() << " (Fiyat: " << u->get_fiyat() << " TL)" << endl;
        }

        cout << "\n3. En Cok Satan Urunler (Top 3):" << endl;
        auto topUrunler = eticaret.enCokSatanUrunler(3);
        for(const auto& u : topUrunler) {
            cout << "   - " << u->get_ad() << endl; 
        }

        cout << "\n4. Gunluk Satis Raporu:" << endl;
        string rapor = eticaret.gunlukSatisRaporu(TarihUtils::bugunTarihi());
        cout << rapor << endl;

    } catch (const exception& e) {
        cerr << "!!! HATA !!! : " << e.what() << endl;
    }

    cout << endl;

    // 5. Sistem Özeti
    cout << "[5] Sistem Ozeti:" << endl;
    cout << " - Toplam Kategori : " << kategoriDepo.boyut() << endl;
    cout << " - Toplam Urun     : " << urunDepo.boyut() << endl;
    cout << " - Toplam Musteri  : " << musteriDepo.boyut() << endl;
    cout << " - Toplam Siparis  : " << siparisDepo.boyut() << endl;
    cout << " - Toplam Odeme    : " << odemeDepo.boyut() << endl;
    
    auto iphone = urunDepo.getir(1);
    cout << " - Kalan iPhone Stogu: " << iphone->get_stok() << " (Baslangic: 10)" << endl;

    cout << endl << "=== PROGRAM BASARIYLA TAMAMLANDI ===" << endl;

    return 0;
}