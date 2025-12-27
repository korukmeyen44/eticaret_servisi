#include "siparis.hpp"

// Varsayılan ilklendirici
// Sayısal değerleri sıfırlar.
Siparis::Siparis() : id(0), musteri_id(0), adres_id(0), toplam_tutar(0.0) {
}

// Parametreli ilklendirici
Siparis::Siparis(int id, int musteri_id, int adres_id, const std::string& tarih,
                 const std::string& durum, double toplam_tutar)
    : id(id), musteri_id(musteri_id), adres_id(adres_id), 
      tarih(tarih), durum(durum), toplam_tutar(toplam_tutar) {
}

// Kopya ilklendirici
// Başka bir sipariş nesnesinin verilerini kopyalar.
Siparis::Siparis(const Siparis& other)
    : id(other.id), musteri_id(other.musteri_id), adres_id(other.adres_id),
      tarih(other.tarih), durum(other.durum), toplam_tutar(other.toplam_tutar) {
}

// Sonlandırıcı
Siparis::~Siparis() {
    // Bellek yönetimi otomatiktir.
}

// Depo şablonu için zorunlu metod
int Siparis::get_id() const {
    return id;
}

// Depo sınıfının otomatik ID atayabilmesi için zorunlu metod
void Siparis::set_id(int yeni_id) {
    id = yeni_id;
}

// Getterlar
int Siparis::get_musteri_id() const {
    return musteri_id;
}

int Siparis::get_adres_id() const {
    return adres_id;
}

std::string Siparis::get_tarih() const {
    return tarih;
}

std::string Siparis::get_durum() const {
    return durum;
}

double Siparis::get_toplam_tutar() const {
    return toplam_tutar;
}

// Setterlar

// Sipariş durumu değiştiğinde (Örn: Ödeme alındı, İptal edildi) kullanılır
void Siparis::set_durum(const std::string& yeni_durum) {
    durum = yeni_durum;
}

// Sepete ürün eklendiğinde tutarı güncellemek için kullanılır
void Siparis::set_toplam_tutar(double yeni_tutar) {
    toplam_tutar = yeni_tutar;
}