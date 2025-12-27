#include "kategori.hpp"

// Varsayılan ilklendirici
// Sayısal değerleri 0 yapar, stringler otomatik olarak boş başlatılır.
Kategori::Kategori() : id(0), ust_kategori_id(0) {
}

// Parametreli ilklendirici
Kategori::Kategori(int id, const std::string& ad, int ust_kategori_id)
    : id(id), ad(ad), ust_kategori_id(ust_kategori_id) {
}

// Kopya ilklendirici
// Başka bir Kategori nesnesinin verilerini buna kopyalar.
Kategori::Kategori(const Kategori& other)
    : id(other.id), ad(other.ad), ust_kategori_id(other.ust_kategori_id) {
}

// Sonlandırıcı
Kategori::~Kategori() {
}

// Getter ve Setter Implementasyonları

// Depo şablonu için zorunlu metod
int Kategori::get_id() const {
    return id;
}

// Depo sınıfının otomatik ID atayabilmesi için ZORUNLU metod
void Kategori::set_id(int yeni_id) {
    id = yeni_id;
}

// Servis katmanında ürün listelerken kategori adını göstermek için gerekli
std::string Kategori::get_ad() const {
    return ad;
}

// Alt kategori/Üst kategori mantığını yönetmek için gerekli
int Kategori::get_ust_kategori_id() const {
    return ust_kategori_id;
}