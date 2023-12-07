#include "Lab3.h"
#include "Exp.h"

int main() {
    try {
        int choice;
        std::cout << "Choose device type (1-Computer, 2-Dekstop, 3-Monoblock, 4-Portable, 5-Laptop, 6-Tablet): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                computer cmp;
                inputComputerData(&cmp);
                break;
            }
            case 2: {
                dekstop dst;
                inputDekstopData(&dst);
                break;
            }
            case 3: {
                monoblock mnb;
                inputMonoblockData(&mnb);
                break;
            }
            case 4: {
                portalble ptb;
                inputPortableData(&ptb);
                break;
            }
            case 5: {
                laptop lpt;
                inputLaptopData(&lpt);
                break;
            }
            case 6: {
                tablet tbt;
                inputTabletData(&tbt);
                break;
            }
        }
    }
    catch(Exp& e) {
        e.show();
    }


    return 0;
}
