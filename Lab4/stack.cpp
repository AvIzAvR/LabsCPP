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
        for (int i = 0; i < size; i++)
            std::cout << data[i] << std::endl;
}

template<class T>
void stack<T>::push(const T d) {
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

template <typename T>
void stack<T>::printStack() {
    for (auto it = begin(); it != end(); ++it) {
        std::cout << *it << std::endl;
    }
}

template<class T>
typename stack<T>::iterator stack<T>::search(const T& value) {
    for (auto it = this->begin(); it != this->end(); ++it) {
        if (*it == value) {
            return it;
        }
    }
    std::cout << "Element not found" << std::endl;
    return this->end();
}

template <typename T>
T stack<T>::accumulate(const T& init) {
    T sum = init;
    for (auto it = this->begin(); it != this->end(); ++it) {
        sum = sum + *it;
    }
    return sum;
}
