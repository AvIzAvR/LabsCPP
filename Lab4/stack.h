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

    class iterator {
        T *ptr;
    public:
        iterator(T *p) : ptr(p) {}

        iterator operator++() {
            ++ptr;
            return *this;
        }

        iterator& operator--() {
            --ptr;
            return *this;
        }

        T& operator*() {
            return *ptr;
        }

        bool operator!=(const iterator &other) const {
            return ptr != other.ptr;
        }

        bool operator==(const iterator &other) const {
            return ptr == other.ptr;
        }

        const T &operator*() const { return *ptr; }

    };

    iterator begin() { return iterator(data); }

    iterator end() { return iterator(data + size); }

    iterator search(const T& value);

    T accumulate(const T& init);


    void printIterator(typename stack<T>::iterator it) {
        std::cout << *it << std::endl;
    }

    stack() {
        size = 0;
        data = new T[0];
    }

    void push(T d);
    void print();
    void pop();
    void printStack();
    T peek();
    bool isFull();
    bool isNull();

    ~stack() {
        delete[] data;
    }

    stack& operator=(const stack& other) {
        if (this != &other) {
            delete[] data;

            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};


#endif //LABSCPP_STACK_H
