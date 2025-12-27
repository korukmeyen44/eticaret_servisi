/**
 * @file TarihUtils.hpp
 * @brief Tarih donusum islemleri icin yardimci fonksiyonlar
 */

#ifndef TARIH_UTILS_H
#define TARIH_UTILS_H

#include <string>
#include <sstream>
#include <ctime>
#include <iostream>

namespace TarihUtils {

    /**
     * @brief String tarihten yil, ay, gun degerlerini ayiklar (Parser)
     */
    inline bool tarihiAyristir(const std::string& tarih, int& yil, int& ay, int& gun) {
        std::istringstream ss(tarih);
        char ayrac1, ayrac2;

        // "2025-12-15" formatini okumaya calisiyoruz
        if (!(ss >> yil >> ayrac1 >> ay >> ayrac2 >> gun)) {
            return false;
        }

        if (ayrac1 != '-' || ayrac2 != '-') return false;
        if (ay < 1 || ay > 12) return false;
        if (gun < 1 || gun > 31) return false;

        return true;
    }

    /**
     * @brief String tarihi time_t formatina cevirir
     */
    inline time_t stringToTime(const std::string& tarih) {
        int yil, ay, gun;

        if (!tarihiAyristir(tarih, yil, ay, gun)) {
            return -1; 
        }

        std::tm tm = {};
        tm.tm_year = yil - 1900;
        tm.tm_mon = ay - 1;
        tm.tm_mday = gun;
        tm.tm_hour = 0;
        tm.tm_min = 0;
        tm.tm_sec = 0;
        tm.tm_isdst = -1;

        return std::mktime(&tm);
    }

    /**
     * @brief time_t degerini String tarih (YYYY-MM-DD) formatina cevirir
     */
    inline std::string timeToString(time_t zaman) {
        if (zaman == -1) return "Hatali Tarih";

        std::tm* tmPtr = std::localtime(&zaman);
        std::ostringstream ss;

        ss << (tmPtr->tm_year + 1900) << "-";
        if (tmPtr->tm_mon + 1 < 10) ss << "0";
        ss << (tmPtr->tm_mon + 1) << "-";

        if (tmPtr->tm_mday < 10) ss << "0";
        ss << tmPtr->tm_mday;

        return ss.str();
    }

    /**
     * @brief Iki string tarih arasindaki gun farkini hesaplar
     */
    inline int gunFarki(const std::string& tarih1, const std::string& tarih2) {
        time_t t1 = stringToTime(tarih1);
        time_t t2 = stringToTime(tarih2);

        if (t1 == -1 || t2 == -1) return 0; 

        double saniyeFarki = std::difftime(t2, t1);
        return static_cast<int>(saniyeFarki / (60 * 60 * 24));
    }

    /**
     * @brief Bugunun tarihini string formatinda dondurur
     */
    inline std::string bugunTarihi() {
        time_t simdi = std::time(nullptr);
        return timeToString(simdi);
    }

    /**
     * @brief Verilen bir tarihe belirli sayida gun ekler
     */
    inline std::string gunEkle(const std::string& tarih, int gunSayisi) {
        time_t t = stringToTime(tarih);
        if (t == -1) return "Hatali Tarih";
        
        t += (gunSayisi * 24 * 60 * 60);
        return timeToString(t);
    }

} // namespace TarihUtils

#endif // TARIH_UTILS_H