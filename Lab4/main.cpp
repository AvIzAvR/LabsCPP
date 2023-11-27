#include "iostream"
#include "string"

#define MAX_SIZE 1000

template<class T>
class stack {
private:
    T *data;
    int size;
public:
    stack() {
        size = 0;
        data = new T[0];
    }

    void push(T d);
    void print();
    void pop();
    T peek();
    bool isFull();
    bool isNull();

    ~stack() {
        delete[] data;
    }
};

template<class T>
bool stack<T>::isFull() {
    return size >= MAX_SIZE;
}

template<class T>
bool stack<T>::isNull() {
    return size == 0;
}

template<class T>
void stack<T>::push(T d) {
    if(!isFull()) {
        T *temp = new T[size];
        std::copy(data, data + size, temp);
        temp[size] = d;
        delete[] data;
        data = temp;
        size++;
    }
    else
        std::cout << "Stack overflow" << std::endl;
}

template<class T>
void stack<T>::print() {
    if(!isNull()) {
        for (int i = size - 1; i != 0; i--)
            std::cout << data[i] << std::endl;
    }
    else
        std::cout << "Stack is empty" << std::endl;
}

template<class T>
void stack<T>::pop() {
    if(!isNull()) {
        size--;
        T *temp = new T[size];
        std::copy(data, data + size, temp);
        delete[] data;
        data = temp;
    }
    else
        std::cout << "Stack is empty" << std::endl;

}

template<class T>
T stack<T>::peek() {
    return data[size-1];
}

int main() {
    stack<char> st;
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('d');
    std::cout << "Original Stack:" << std::endl;
    st.print();

    std::cout << "Remove element:" << std::endl;
    st.pop();
    st.print();

    std::cout<< "Element:" << st.peek() << std::endl;

}