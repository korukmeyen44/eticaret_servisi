#ifndef SIPARIS_KALEMI_HPP
#define SIPARIS_KALEMI_HPP

class SiparisKalemi {
private:
    int id;
    int siparis_id;
    int urun_id;
    int miktar;
    double birim_fiyat;

public:
    // Varsayılan ilklendirici
    SiparisKalemi();

    // Parametreli ilklendirici
    SiparisKalemi(int id, int siparis_id, int urun_id, int miktar, double birim_fiyat);

    // Kopya ilklendirici
    SiparisKalemi(const SiparisKalemi& other);

    // Sonlandırıcı
    ~SiparisKalemi();

    // Getterlar
    
    // Depo için zorunlu metodlar
    int get_id() const;
    void set_id(int id);
    int get_siparis_id() const;
    int get_urun_id() const;
    int get_miktar() const;
    double get_birim_fiyat() const;
};

#endif // SIPARIS_KALEMI_HPP