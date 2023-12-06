#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"
#include "Exp.h"

#define MAX_SIZE 3

template<class T>
bool stack<T>::isFull() {
    return size >= MAX_SIZE;
}

template<class T>
bool stack<T>::isNull() {
    return size == 0;
}

template<class T>
void stack<T>::print() {
    if (!isNull()) {
        for (int i = size - 1; i != -1; i--)
            std::cout << data[i] << std::endl;
    } else
        throw ExpStackEmpty(3, "Stack is empty");
}

template<class T>
void stack<T>::push(T d) {
    if (!isFull()) {
        T *temp = new T[size + 1];
        std::copy(data, data + size, temp);
        temp[size] = d;
        delete[] data;
        data = temp;
        size++;
    } else {
        throw ExpStackOverflow(1, "StackOverflow");
    }
}

template<class T>
void stack<T>::pop() {
    if (!isNull()) {
        size--;
        T *temp = new T[size];
        std::copy(data, data + size, temp);
        delete[] data;
        data = temp;
    } else {
        throw ExpUnderflow(2, "Stack Underflow");
    }
}

template<class T>
T stack<T>::peek() {
    if (!isNull()) {
        return data[size - 1];
    }
    else
        throw ExpStackEmpty(3, "Stack is empty");
}

