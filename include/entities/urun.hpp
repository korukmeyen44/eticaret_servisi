#ifndef URUN_HPP
#define URUN_HPP

#include <string>

class Urun {
private:
    int id;
    std::string ad;
    std::string aciklama;
    double fiyat;
    int stok;
    int kategori_id;

public:
    // Varsayılan ilklendirici
    Urun();

    // Parametreli ilklendirici
    Urun(int id, const std::string& ad, const std::string& aciklama,
         double fiyat, int stok, int kategori_id);

    // Kopya ilklendirici
    Urun(const Urun& other);

    // Sonlandırıcı
    ~Urun();

    // Getterlar
    int get_id() const;
    std::string get_ad() const;
    std::string get_aciklama() const;
    double get_fiyat() const;
    int get_stok() const;
    int get_kategori_id() const;

    // Setterlar
    void set_id(int id);
    void set_stok(int yeni_stok);
};

#endif // URUN_HPP