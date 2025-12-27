#ifndef ODEME_HPP
#define ODEME_HPP

#include <string>

class Odeme {
private:
    int id;
    int siparis_id;
    std::string yontem;
    double tutar;
    std::string tarih;
    std::string durum;

public:
    // Varsayılan ilklendirici
    Odeme();

    // Parametreli ilklendirici
    Odeme(int id, int siparis_id, const std::string& yontem, double tutar,
          const std::string& tarih, const std::string& durum);

    // Kopya ilklendirici
    Odeme(const Odeme& other);

    // Sonlandırıcı
    ~Odeme();

    // Getterlar ve Setterlar
    // Depo için zorunlu metodlar
    int get_id() const;
    void set_id(int id);

    // Servis katmanı için gerekli getter'lar
    int get_siparis_id() const;
    std::string get_yontem() const;
    double get_tutar() const;
    std::string get_tarih() const;
    std::string get_durum() const;
};

#endif // ODEME_HPP