#include<iostream>
#include<fstream>
#include<cstring>
#include<iostream>
#include<sstream>
#include "Lab3.h"
#include "Lab3.cpp"
#include "stack.h"
#include "stack.cpp"

class File {
    char filename[80];
    std::fstream fstr;
public:
    File(const char *filename) {
        strcpy(this->filename, filename);
        fstr.open(filename, std::ios::in | std::ios::out | std::ios::binary);
        if (!fstr.is_open()) {
            throw ExpFile(7, "Failed to open file");
        }
    }

    template <typename T>
    void write(const T& obj) {
        fstr.write(reinterpret_cast<const char*>(&obj), sizeof(T));
    }

    template <typename T>
    void read(T& obj) {
        fstr.read(reinterpret_cast<char*>(&obj), sizeof(T));
    }

    template <typename T>
    void writeStackToFile(stack<T>& s) {
        File file(filename);
        while (!s.isNull()) {
            T obj = s.peek();
            fstr << obj << std::endl;
            s.pop();
        }
    }

    template <typename T>
    void readStackFromFile(stack<T>& s) {
        File file(filename);
        T obj;
        while (true) {
            file.fstr >> obj;
            if(file.fstr.eof() || file.fstr.fail())
                break;
            s.push(obj);
        }
    }


    void writeString(const std::string& str) {
        size_t length = str.length();
        write(length);
        fstr.write(str.c_str(), length);
    }

    std::string readString() {
        size_t length;
        read(length);
        char* buffer = new char[length + 1];
        fstr.read(buffer, length);
        buffer[length] = '\0';
        std::string str(buffer);
        delete[] buffer;
        return str;
    }

    void serializeComputerBin(File& file, computer& cmp) {
        file.writeString(cmp.getBrand());
        file.writeString(cmp.getModel());
        file.writeString(cmp.getVideoCard());
    }

    computer deserializeComputerBin(File& file) {
        computer cmp;
        std::string brand = file.readString();
        std::string model = file.readString();
        std::string videocard = file.readString();
        cmp.setBrand(brand.c_str());
        cmp.setModel(model.c_str());
        cmp.setVideoCard(videocard.c_str());
        return cmp;
    }

    template <typename T>
    void writeStackToFileBin(stack<T>& s) {
        File file(filename);
        while (!s.isNull()) {
            T obj = s.peek();
            serializeComputerBin(file, obj);
            s.pop();
        }
    }

    template <typename T>
    void readStackFromFileBin(stack<T>& s) {
        File file(filename);
        while (!file.fstr.eof()) {
            T obj = deserializeComputerBin(file);
            if(file.fstr.eof()) break;
            s.push(obj);
        }
    }


    ~File() {
        if (fstr.is_open()) {
            fstr.close();
        }
    }
};


