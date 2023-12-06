#include "stack.h"
#include "stack.cpp"

bool isInteger(const std::string& str) {
    std::stringstream stream(str);
    int n;
    char c;

    if (stream >> n && !(stream >> c)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    stack<int> myStack;
    try {
        std::string str;
        int number;
        std::cout << "Write elements:" << std::endl;
        for(int i = 0; i < 4; i++) {
            std::cin >> str;
            if (!isInteger(str)) {
                throw ExpInput(4, "Invalid input. Not an integer.");
            }
            std::stringstream convert(str);
            convert >> number;
            myStack.push(number);
        }
    }
    catch (Exp& e) {
        e.show();
        return 0;
    }

    myStack.print();

    try {
        while(true) {
            std::cout << "Top element: " << myStack.peek() << std::endl;
            myStack.pop();
        }
    }
    catch (Exp& e) {
        e.show();
    }



    return 0;
}





