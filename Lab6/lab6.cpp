#include "lab6.h"


int main() {
    int choice;
    std::cout << "Enter the data for your computer" << std::endl;
    computer cmp;
    inputComputerData(&cmp);
    std::cout << "Enter the data for your computer2" << std::endl;
    computer cmp2;
    inputComputerData(&cmp2);
    try {
        File file("C:/gitHub/LabsCPP/Lab6/test.txt");
        File fileBin("C:/gitHub/LabsCPP/Lab6/testBin.txt");
        stack<computer> myStack;
        stack<computer> myStackBin;
        stack<computer> stackOpen;
        stack<computer> stackOpenBin;
        myStack.push(cmp);
        myStack.push(cmp2);

        myStackBin = myStack;

        std::cout << "Text:" << std::endl;
        file.writeStackToFile(myStack);
        file.readStackFromFile(stackOpen);
        stackOpen.print();

        std::cout << "Bin:" << std::endl;
        fileBin.writeStackToFileBin(myStackBin);
        fileBin.readStackFromFileBin(stackOpenBin);
        stackOpenBin.print();
    }
    catch (Exp& e) {
        e.show();
        return 0;
    }
}