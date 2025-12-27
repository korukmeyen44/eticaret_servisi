#ifndef KATEGORI_HPP
#define KATEGORI_HPP

#include <string>

class Kategori {
private:
    int id;
    std::string ad;
    int ust_kategori_id;

public:
    // Varsayılan ilklendirici
    Kategori();

    // Parametreli ilklendirici
    Kategori(int id, const std::string& ad, int ust_kategori_id = 0);

    // Kopya ilklendirici
    Kategori(const Kategori& other);

    // Sonlandırıcı
    ~Kategori();

    // Getterlar
    int get_id() const;
    void set_id(int id);

    std::string get_ad() const;
    int get_ust_kategori_id() const;
};

#endif // KATEGORI_HPP