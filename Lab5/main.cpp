#include <iostream>
#include "Exp.h"
using namespace std;

void int_exception(int i) {
    if (i > 100) throw 1; // генерация исключения типа int
}

//void string_exception() {
//    throw "Error"; // генерация исключения типа char *
//}

int main() {
    try { // в блоке возможна обработка одного из двух исключений
        int_exception(101); // возможно исключение типа int
//        string_exception(); // возможно исключение типа char *
    }
    catch (int) {
        Exp test(1, "Drop");
    }
}