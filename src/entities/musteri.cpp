#include "musteri.hpp"

// Varsayılan ilklendirici
// Sayısal değerleri sıfırlar, stringler otomatik olarak boş başlatılır.
Musteri::Musteri() : id(0) {
}

// Parametreli ilklendirici
Musteri::Musteri(int id, const std::string& email, const std::string& ad_soyad,
                 const std::string& telefon, const std::string& kayit_tarihi)
    : id(id), email(email), ad_soyad(ad_soyad), telefon(telefon), kayit_tarihi(kayit_tarihi) {
}

// Kopya ilklendirici
// Gelen nesnenin verilerini yeni nesneye kopyalar.
Musteri::Musteri(const Musteri& other)
    : id(other.id), email(other.email), ad_soyad(other.ad_soyad),
      telefon(other.telefon), kayit_tarihi(other.kayit_tarihi) {
}

// Sonlandırıcı
Musteri::~Musteri() {
    // std::string bellek yönetimini kendi yaptığı için burası boş kalabilir.
}

// Getter ve Setter Implementasyonları

// Depo şablonu için zorunlu metod
int Musteri::get_id() const {
    return id;
}

// Depo sınıfının otomatik ID atayabilmesi için
void Musteri::set_id(int yeni_id) {
    id = yeni_id;
}

// Servis katmanının verilere erişebilmesi için gerekli metodlar
std::string Musteri::get_email() const {
    return email;
}

std::string Musteri::get_ad_soyad() const {
    return ad_soyad;
}

std::string Musteri::get_telefon() const {
    return telefon;
}

std::string Musteri::get_kayit_tarihi() const {
    return kayit_tarihi;
}