#include "siparisKalemi.hpp"
// Varsayılan ilklendirici
// Sayısal değerleri sıfırlar.
SiparisKalemi::SiparisKalemi() 
    : id(0), siparis_id(0), urun_id(0), miktar(0), birim_fiyat(0.0) {
}

// Parametreli ilklendirici
SiparisKalemi::SiparisKalemi(int id, int siparis_id, int urun_id, int miktar, double birim_fiyat)
    : id(id), siparis_id(siparis_id), urun_id(urun_id), miktar(miktar), birim_fiyat(birim_fiyat) {
}

// Kopya ilklendirici
// Başka bir nesnenin verilerini buna kopyalar.
SiparisKalemi::SiparisKalemi(const SiparisKalemi& other)
    : id(other.id), siparis_id(other.siparis_id), urun_id(other.urun_id),
      miktar(other.miktar), birim_fiyat(other.birim_fiyat) {
}

// Sonlandırıcı
SiparisKalemi::~SiparisKalemi() {
    // Bellek yönetimi otomatiktir.
}

// Depo şablonu için zorunlu metod
int SiparisKalemi::get_id() const {
    return id;
}

// Depo sınıfının otomatik ID atayabilmesi için zorunlu metod
void SiparisKalemi::set_id(int yeni_id) {
    id = yeni_id;
}

// Getterlar

int SiparisKalemi::get_siparis_id() const {
    return siparis_id;
}

int SiparisKalemi::get_urun_id() const {
    return urun_id;
}

int SiparisKalemi::get_miktar() const {
    return miktar;
}

double SiparisKalemi::get_birim_fiyat() const {
    return birim_fiyat;
}