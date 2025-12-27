# E-Ticaret Sipariş Sistemi (C++ Projesi)

Bu proje, **Yazılım Geliştirme I** dersi kapsamında geliştirilmiş, 3 katmanlı mimari (3-Tier Architecture) prensiplerine dayalı konsol tabanlı bir e-ticaret simülasyonudur.

## 📋 Proje Hakkında

Bu sistem, temel bir e-ticaret platformunun işleyişini modeller. Müşteri kaydından sipariş oluşturmaya, stok takibinden satış raporlamaya kadar olan süreci nesne yönelimli programlama (OOP) teknikleri kullanarak simüle eder.

### 🎯 Temel Özellikler
* **Müşteri Yönetimi:** Yeni müşteri kaydı ve adres tanımlama.
* **Ürün Kataloğu:** Kategori ve ürün ekleme işlemleri.
* **Sipariş İşlemleri:** Sepete ürün ekleme, sipariş oluşturma ve onaylama.
* **Stok Kontrolü:** Sipariş anında dinamik stok kontrolü ve düşümü.
* **Raporlama:** Günlük ciro raporu, en çok satan ürünler ve müşteri sipariş geçmişi.
* **Generic Depo:** C++ Template yapısı ile türden bağımsız veri saklama (Repository Pattern).

## 🏗️ Mimari Yapı

Proje, sorumlulukların ayrılması ilkesine göre 3 ana katmana ayrılmıştır:

1.  **Varlık Katmanı (Entities):** Veri modellerini içerir (`Musteri`, `Urun`, `Siparis` vb.). Sadece veri tutar ve temel getter/setter metodları vardır.
2.  **Depo Katmanı (Repositories):** Veriye erişimi yönetir (`Depo<T>`). CRUD (Ekle, Oku, Güncelle, Sil) işlemleri burada yapılır. Defensive Copy stratejisi ile veriler korunur.
3.  **Servis Katmanı (Services):** İş mantığını içerir (`ETicaretServisi`). Stok kontrolü, tutar hesaplama ve raporlama gibi kurallar burada işlenir.

🛠️ Kullanım Senaryosu (Main.cpp)
Program çalıştırıldığında main.cpp içindeki senaryo otomatik olarak işler:

Sistem çalışmaya ve Depo nesneleri oluşturulur.
Örnek veriler (Kategoriler, Ürünler, Müşteriler) yüklenir.
Bir müşteri için sipariş oluşturulur.
Sepete ürün eklenirken stok kontrolü yapılır.
Ödeme alınır ve sipariş onaylanır.
Konsola raporlar ve sistem özeti basılır.

## 📂 Klasör Yapısı

```text
E-Ticaret-Siparis/
├── CMakeLists.txt          # Derleme yapılandırma dosyası
├── GONDERIM.md             # Grup üyeleri ve proje notları
├── README.md               # Proje dökümantasyonu
├── .gitignore              # Gereksiz dosyalar
├── src/                    # Kaynak kodlar (.cpp)
│   ├── main.cpp            # Ana program ve test senaryosu
│   ├── services/           # Servis implementasyonları
│   └── entities/           # Varlık implementasyonları
└── include/                # Başlık dosyaları (.hpp)
    ├── entities/           # Varlık tanımları
    ├── repositories/       # Generic Depo şablonu
    ├── services/           # Servis tanımları
    └── utils/              # Yardımcı araçlar (TarihUtils vb.)

