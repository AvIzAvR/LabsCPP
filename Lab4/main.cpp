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
        for(int i = 0; i < MAX_SIZE; i++) {
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

    auto it = myStack.begin();
    myStack.printIterator(it);
    ++it;
    myStack.printIterator(it);
    it = myStack.search(3);
    myStack.printIterator(it);

    int x = myStack.accumulate(2);
    std::cout << "Sum:" << x << std::endl;






    return 0;
}





