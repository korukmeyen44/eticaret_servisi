#ifndef MUSTERI_HPP
#define MUSTERI_HPP

#include <string>

class Musteri {
private:
    int id;
    std::string email;
    std::string ad_soyad;
    std::string telefon;
    std::string kayit_tarihi;

public:
    // Varsayılan ilklendirici
    Musteri();

    // Parametreli ilklendirici
    Musteri(int id, const std::string& email, const std::string& ad_soyad,
            const std::string& telefon, const std::string& kayit_tarihi);

    // Kopya ilklendirici
    Musteri(const Musteri& other);

    // Sonlandırıcı
    ~Musteri();

    // Getterlar
    int get_id() const;
    
    void set_id(int id);

    std::string get_email() const;
    std::string get_ad_soyad() const;
    std::string get_telefon() const;
    std::string get_kayit_tarihi() const;
};

#endif // MUSTERI_HPP