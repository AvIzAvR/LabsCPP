#include "Lab3.h"
#include "Exp.h"

bool isValidData(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

void inputComputerData(computer* cmp) {
    char brand[50], model[50], videocard[50];

    std::cout << "Enter computer brand: ";
    std::cin >> brand;
    cmp->setBrand(brand);

    std::cout << "Enter computer model: ";
    std::cin >> model;
    cmp->setModel(model);

    std::cout << "Enter videocard: ";
    std::cin >> videocard;
    cmp->setVideoCard(videocard);
}

void inputDekstopData(dekstop* dst) {
    char corpus[50];
    int memorySize;

    inputComputerData(dst);

    std::cout << "Enter dekstop corpus: ";
    std::cin >> corpus;
    dst->setCorpus(corpus);

    std::cout << "Enter memory size: ";
    std::cin >> memorySize;
    dst->setMemorySize(memorySize);
}

void inputMonoblockData(monoblock* mb) {
    char motherboard[50];
    double diagonal;

    inputDekstopData(mb); // Наследованные атрибуты

    std::cout << "Enter monoblock diagonal: ";
    std::cin >> diagonal;
    mb->setDiagonal(diagonal);

    std::cout << "Enter motherboard type: ";
    std::cin >> motherboard;
    mb->setMotherboard(motherboard);
}

void inputPortableData(portalble* pt) {
    int change;
    double diagonal;
    bool camera;

    inputComputerData(pt); // Наследованные атрибуты

    std::cout << "Enter battery change: ";
    std::cin >> change;
    pt->setChange(change);

    std::cout << "Enter screen diagonal: ";
    std::cin >> diagonal;
    pt->setDiagonal(diagonal);

    std::cout << "Has camera (1 for yes, 0 for no): ";
    std::cin >> camera;
    pt->setCamera(camera);
}

void inputLaptopData(laptop* lp) {
    int keys;
    bool fingerprint;

    inputPortableData(lp); // Наследованные атрибуты

    std::cout << "Enter number of keys: ";
    std::cin >> keys;
    lp->setKeys(keys);

    std::cout << "Has fingerprint (1 for yes, 0 for no): ";
    std::cin >> fingerprint;
    lp->setFingerprint(fingerprint);
}

void inputTabletData(tablet* tb) {
    char modem[50];
    int megapixels;

    inputPortableData(tb); // Наследованные атрибуты

    std::cout << "Enter modem type: ";
    std::cin >> modem;
    tb->setModem(modem);

    std::cout << "Enter camera megapixels: ";
    std::cin >> megapixels;
    tb->setMegapixel(megapixels);
}