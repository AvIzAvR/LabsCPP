//
// Created by User on 27.11.2023.
//
#include "iostream"
#include "string"

#ifndef LABSCPP_STACK_H
#define LABSCPP_STACK_H

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


#endif //LABSCPP_STACK_H
