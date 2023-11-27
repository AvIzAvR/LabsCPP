#include <iostream>

using namespace std;


//Написать класс для работы с символьными строками. Память под строку
//отводить динамически. Перегрузить операторы
//=
//+
//+=
//==
//!=
//[]
//()(int, int)

class strings {
private:
    char* str;
    int len;
public:
    strings(char* s) {
        int strlen = 0;
        for(int i = 0; s[i] != '\n' && s[i] != '\0'; i++)
            strlen = i+1;
            if(s) {
                str = new char[strlen + 1];
                for(int i = 0; i <= strlen; i++) {
                    str[i] = s[i];
                }
                str[strlen] = '\0';
                this->len = strlen;
            }
            else
                str = nullptr;
        }

        int getlen() const { return len; }
        char* getstr() const { return str; }

        bool operator==(const strings& other) {
            if(this->len != other.len)
                return false;
            for(int i = 0; i < this->len; i++)
                if(this->str[i] != other.str[i])
                    return false;
            return true;
        }

    bool operator!=(const strings& other) {
        if(this->len != other.len)
            return true;
        for(int i = 0; i < this->len; i++)
            if(this->str[i] != other.str[i])
                return true;
        return false;
    }
        strings operator+(const strings& other) {
            char* temp = new char[this->len + other.len + 1];
            for(int i = 0; i < this->len; i++)
                temp[i] = this->str[i];
            for(int i = 0; i < other.len; i++)
                temp[this->len + i] = other.str[i];
            temp[this->len + other.len + 1] = '\0';
            strings s(temp);
            return s;
        }

    strings* operator+=(const strings& other) {
        char* temp = new char[this->len + other.len + 1];
        for(int i = 0; i < this->len; i++) {
            temp[i] = this->str[i];
        }
        for(int i = 0; i < other.len; i++)
            temp[this->len + i] = other.str[i];
        temp[this->len + other.len + 1] = '\0';
        delete [] this->str;
        this->str = temp;
        this->len = this->len + other.len;
        return this;
    }

        strings* operator= (const strings& other) {
        this->str = new char[other.len];
        this->len = other.len;
        for(int i = 0; i < other.len; i++)
            this->str[i] = other.str[i];
            return this;
        }

    char& operator[](int index) { return str[index];}

    void operator() (int index, int index_two) {
           for(int i = index; i <= index_two; i++)
               cout << this->str[i];
    }

    friend ostream& operator<<(ostream& stream, const strings& s);
    };

ostream& operator<<(ostream& stream, const strings& s) {
    for (int i = 0; i < s.getlen(); i++)
        stream << s.getstr()[i];
    return stream;
}

int main() {
    strings s1("Ara");
    strings s2("Ara");
    strings s3("Araa");
    bool t1 = s1 == s2;
    bool t2 = s1 == s3;
    cout << "s1 == s2?: "<< t1 << endl;
    cout << "s1 == s3?: "<< t2 << endl;

    bool t3 = s1 != s2;
    bool t4 = s1 != s3;
    cout << "s1 != s2?: "<< t3 << endl;
    cout << "s1 != s3?: "<< t4 << endl;

    cout << "s3(1, 3):";
    s3(0, 2);

    cout << "\ns1[1]: " << s1[1] << endl;


    strings s4(s1 + s3);
    cout << "s1 + s3:"<< s4 << endl;

    s1 += s2;

    cout << "s1 += s2:" << s1 << endl;

    s3 = s1;
    cout << "s3 = s1:" << s3 << endl;

}
