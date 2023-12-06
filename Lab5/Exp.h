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
    ExpStackOverflow(int code_t, char* msg_t) : Exp(code_t,msg_t) {};
};

class ExpUnderflow : public Exp {
public:
    ExpUnderflow(int code_t, char* msg_t) : Exp(code_t,msg_t) {};
};

class ExpStackEmpty : public Exp {
public:
    ExpStackEmpty(int code_t, char* msg_t) : Exp(code_t,msg_t) {};
};


class ExpInput : public Exp{
public:
    ExpInput(int code_t, char* msg_t) : Exp(code_t,msg_t) {};
};

class ExpFile : public Exp{
public:
    ExpFile(int code_t, char* msg_t) : Exp(code_t, msg_t) {};
};

class ExpCout : public Exp{
public:
    ExpCout(int code_t, char* msg_t) : Exp(code_t, msg_t) {};
};
#endif//LABSCPP_EXP_H
