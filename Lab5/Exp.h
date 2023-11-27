#ifndef LABSCPP_EXP_H
#define LABSCPP_EXP_H

#include "cstring"
#include "iostream"

class Exp {
    int code;
    char msg[80];
public:
    Exp(int code_t, const char msg_t[80]) {
        code = code_t;
        strcpy(msg, msg_t);
    }

    void show() {
        std::cout << "Error: " << code << " " << msg << std::endl;
    }
};

class ExpStackOverflow : public Exp{
public:
    ExpStackOverflow() : Exp(1, "StackOverflow") {};
};

class ExpUnderflow : public Exp {
public:
    ExpUnderflow() : Exp(2, "Stack Underflow") {};
};

class ExpStackEmpty : public Exp {
public:
    ExpStackEmpty() : Exp(3, "Stack is empty") {};
};


class ExpInput : public Exp{
public:
    ExpInput() : Exp(4, "Invalid input. Not an integer.") {};
};

#endif//LABSCPP_EXP_H
