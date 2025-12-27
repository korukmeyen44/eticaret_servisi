#include "odeme.hpp"

// Varsayılan ilklendirici
// Sayısal değerleri sıfırlar. Stringler otomatik boş başlar.
Odeme::Odeme() : id(0), siparis_id(0), tutar(0.0) {
}

// Parametreli ilklendirici
Odeme::Odeme(int id, int siparis_id, const std::string& yontem, double tutar,
             const std::string& tarih, const std::string& durum)
    : id(id), siparis_id(siparis_id), yontem(yontem), tutar(tutar),
      tarih(tarih), durum(durum) {
}

// Kopya ilklendirici
// Başka bir ödeme nesnesinin verilerini kopyalar.
Odeme::Odeme(const Odeme& other)
    : id(other.id), siparis_id(other.siparis_id), yontem(other.yontem),
      tutar(other.tutar), tarih(other.tarih), durum(other.durum) {
}

// Sonlandırıcı
Odeme::~Odeme() {
    // Bellek yönetimi otomatik yapıldığı için gövde boş.
}

// Depo şablonu için zorunlu metod
int Odeme::get_id() const {
    return id;
}

// Depo sınıfının otomatik ID atayabilmesi için zorunlu metod
void Odeme::set_id(int yeni_id) {
    id = yeni_id;
}

// Servis Katmanı İçin Gerekli Getterlar

int Odeme::get_siparis_id() const {
    return siparis_id;
}

std::string Odeme::get_yontem() const {
    return yontem;
}

double Odeme::get_tutar() const {
    return tutar;
}

std::string Odeme::get_tarih() const {
    return tarih;
}

std::string Odeme::get_durum() const {
    return durum;
}