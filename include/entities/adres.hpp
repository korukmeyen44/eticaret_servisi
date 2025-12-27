#ifndef ADRES_HPP
#define ADRES_HPP

#include <string>

class Adres {
private:
    int id;
    int musteri_id;
    std::string baslik;
    std::string il;
    std::string ilce;
    std::string mahalle;
    std::string detay;
    std::string posta_kodu;

public:
    // Varsayılan ilklendirici
    Adres();

    // Parametreli ilklendirici
    Adres(int id, int musteri_id, const std::string& baslik, const std::string& il,
          const std::string& ilce, const std::string& mahalle,
          const std::string& detay, const std::string& posta_kodu);

    // Kopya ilklendirici
    Adres(const Adres& other);

    // Sonlandırıcı
    ~Adres();

    // Getterlar
    int get_id() const;           
    void set_id(int id);            

    int get_musteri_id() const;
    std::string get_baslik() const;
    std::string get_il() const;
    std::string get_ilce() const;
    std::string get_mahalle() const;
    std::string get_detay() const;
    std::string get_posta_kodu() const;
};

#endif // ADRES_HPP