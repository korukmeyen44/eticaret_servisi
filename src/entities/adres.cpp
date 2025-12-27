#include "adres.hpp"

// Varsayılan ilklendirici
Adres::Adres() : id(0), musteri_id(0) {
}

// Parametreli ilklendirici
Adres::Adres(int id, int musteri_id, const std::string& baslik, const std::string& il,
             const std::string& ilce, const std::string& mahalle,
             const std::string& detay, const std::string& posta_kodu)
    : id(id), musteri_id(musteri_id), baslik(baslik), il(il),
      ilce(ilce), mahalle(mahalle), detay(detay), posta_kodu(posta_kodu) {
}

// Kopya ilklendirici
Adres::Adres(const Adres& other)
    : id(other.id), musteri_id(other.musteri_id), baslik(other.baslik),
      il(other.il), ilce(other.ilce), mahalle(other.mahalle),
      detay(other.detay), posta_kodu(other.posta_kodu) {
}

// Sonlandırıcı
Adres::~Adres() {
}

// Metod Implementasyonları

int Adres::get_id() const {
    return id;
}

void Adres::set_id(int yeni_id) {
    id = yeni_id;
}

int Adres::get_musteri_id() const {
    return musteri_id;
}

std::string Adres::get_baslik() const {
    return baslik;
}

std::string Adres::get_il() const {
    return il;
}

std::string Adres::get_ilce() const {
    return ilce;
}

std::string Adres::get_mahalle() const {
    return mahalle;
}

std::string Adres::get_detay() const {
    return detay;
}

std::string Adres::get_posta_kodu() const {
    return posta_kodu;
}