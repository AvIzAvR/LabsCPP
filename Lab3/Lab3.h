#include <iostream>
#include <cstring>
#include <Exp.h>


#ifndef LABSCPP_LAB3_H
#define LABSCPP_LAB3_H

class computer {
    char brand[50];
    char model[50];
    char videocard[50];

public:
    char* getBrand() {
        return brand;
    }
    char* getModel() {
        return model;
    }
    char* getVideoCard() {
        return videocard;
    }
    void setBrand(const char br[50]) {
        strcpy(brand, br);
    }
    void setModel(const char md[50]) {
        strcpy(model, md);
    }
    void setVideoCard(const char vd[50]) {
        strcpy(videocard, vd);
    }

    friend std::ostream& operator<<(std::ostream& os, const computer& cmp) {
        os << cmp.brand << " " << cmp.model << " " << cmp.videocard;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, computer& cmp) {
        is >> cmp.brand >> cmp.model >> cmp.videocard;
        return is;
    }
};

class dekstop : public computer {
    char corpus[50];
    int memorySize;
public:
    char* getCorpus() {
        return corpus;
    }
    void setCorpus(char cp[50]) {
        strcpy(this->corpus, cp);
    }
    int getMemorySize() {
        return memorySize;
    }
    void setMemorySize(int ms) {
        memorySize = ms;
    }
};

class monoblock : public dekstop{
    double diagonal;
    char motherboard[50];
public:
    double getDiagonal() {
        return diagonal;
    }
    void setDiagonal(double dg) {
        diagonal = dg;
    }
    char* getMotherboard() {
        return motherboard;
    }
    void setMotherboard(char* mb) {
        strcpy(this->motherboard, mb);
    }
};

class portalble : public computer {
    int change;
    double diagonal;
    bool camera;
public:
    int getChange() {
        return change;
    }
    double getDiagonal() {
        return diagonal;
    }
    bool getCamera() {
        return camera;
    }
    void setChange(int ch) {
        change = ch;
    }
    void setDiagonal(double dg) {
        diagonal = dg;
    }
    void setCamera(bool cam) {
        camera = cam;
    }
};

class laptop : public portalble {
    int keys;
    bool fingerprint;
public:
    int getKeys() {
        return keys;
    }
    bool getFingerprint() {
        return fingerprint;
    };
    void setKeys(int ks) {
        keys = ks;
    }
    void setFingerprint(bool fg) {
        fingerprint = fg;
    }
};

class tablet : public portalble {
    char modem[50];
    int megapixels;
public:
    char* getModem() {
        return modem;
    }
    int getMegapixel() {
        return megapixels;
    }
    void setModem(char md[50]) {
        strcpy(this->modem, md);
    }
    void setMegapixel(int mg) {
        megapixels = mg;
    }
};

void inputComputerData(computer* cmp);
void inputDekstopData(dekstop* dst);
void inputLaptopData(laptop* lp);
void inputTabletData(tablet* tb);
void inputMonoblockData(monoblock* mb);
void inputPortableData(portalble* pt);

#endif //LABSCPP_LAB3_H
