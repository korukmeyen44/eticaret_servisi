#include "urun.hpp"

// Varsayılan ilklendirici
// Sayısal değerleri sıfırlar, stringler otomatik boş başlar.
Urun::Urun() : id(0), fiyat(0.0), stok(0), kategori_id(0) {
}

// Parametreli ilklendirici
Urun::Urun(int id, const std::string& ad, const std::string& aciklama,
           double fiyat, int stok, int kategori_id)
    : id(id), ad(ad), aciklama(aciklama), 
      fiyat(fiyat), stok(stok), kategori_id(kategori_id) {
}

// Kopya ilklendirici
// Gelen nesnenin verilerini yeni nesneye kopyalar.
Urun::Urun(const Urun& other)
    : id(other.id), ad(other.ad), aciklama(other.aciklama),
      fiyat(other.fiyat), stok(other.stok), kategori_id(other.kategori_id) {
}

// Sonlandırıcı
Urun::~Urun() {
    // Bellek yönetimi otomatiktir.
}

// Depo şablonu için zorunlu metod
int Urun::get_id() const {
    return id;
}

// Depo sınıfının otomatik ID atayabilmesi için zorunlu metod
// (Header dosyasında void set_id(int id); tanımlı olmalıdır)
void Urun::set_id(int yeni_id) {
    id = yeni_id;
}

// Getterlar

std::string Urun::get_ad() const {
    return ad;
}

std::string Urun::get_aciklama() const {
    return aciklama;
}

double Urun::get_fiyat() const {
    return fiyat;
}

int Urun::get_stok() const {
    return stok;
}

int Urun::get_kategori_id() const {
    return kategori_id;
}

// Setterlar

// Sipariş verildiğinde veya stok güncellendiğinde kullanılır
void Urun::set_stok(int yeni_stok) {
    stok = yeni_stok;
}