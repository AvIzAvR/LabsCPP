#include "Lab1.h"

// Определение класса date
class date {
public:
    int year;
    int month;
    int day;
};

// Определение класса employee
class employee {
private:
    enum eType {laborer, secretary, manager, director};
    int num = 0;
    float money;
    date date;
    eType type;

public:

    employee* operator &(const employee &object) {
        return this;
    }

    int operator +(const employee &object) {
        int salary = this->money + object.money;
        return salary;
    }

    int getMoney () {
        return money;
    }


    // Метод для ввода информации о сотруднике
    void putEmploy(float money_t, int year_t, int month_t, int day_t) {
        money = money_t;
        date.year = year_t;
        date.month = month_t;
        date.day = day_t;
        eType prof;

        cout << "Choice work: \n 0 - laborer\n 1 - secretary\n 2 - manager\n3 - director" << endl;
        int checking;
        cin >> checking;

        // Проверка корректности ввода типа сотрудника
        while(true) {
            switch (checking) {
                case 0:
                    prof = laborer;
                    break;
                case 1:
                    prof = secretary;
                    break;
                case 2:
                    prof = manager;
                    break;
                case 3:
                    prof = director;
                    break;
                default:
                    cout << "Retry:" << endl;
                    cout << "Choice work: \n 0 - laborer\n 1 - secretary\n 2 - manager\n3 - director" << endl;
                    fflush(stdin);
                    cin.clear();
                    cin >> checking;
                    break;
            }
            if(checking < 4 && checking >= 0)
                break;
        }
        type = prof;
    }

    // Метод для вывода информации о сотруднике
    void getEmploy(int number) {
        num = number;
        cout << num << '.' << money << "$ ";
        checkZero(date.day);
        checkZero(date.month);
        cout << date.year;
        switch (type) {
            case 0:
                cout << " laborer\n";
                break;
            case 1:
                cout << " secretary\n";
                break;
            case 2:
                cout << " manager\n";
                break;
            case 3:
                cout << " director\n";
                break;
        }
    }
};

//Проверка на количество дней в месяце
int month_check(int month, int day) {
    int x = 0;
    switch (month) {
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        case 1: {
            if(day <= 31)
                x = 1;
            break;
        }
        case 6:
        case 9:
        case 11:
        case 4: {
            if(day <= 30)
                x = 1;
            break;
        }
        case 2: {
            if(day <= 29)
                x = 1;
            break;
        }
        default:
            break;
    }
    return x;
}

// Проверка и добавление нуля к числам с одной цифрой
void checkZero(int x) {
    if(x < 10)
        cout << 0 << x << '.';
    else
        cout << x << '.';
}

// Проверка на некорректный ввод
void check(int x) {
    while(cin.fail() || cin.peek() != '\n') {
        fflush(stdin);
        cin.clear();
        cout << "Retry:" << endl;
        cin >> x;
    }
}


// Проверка на некорректный ввод с учетом диапазона
void check (int x, int y) {
    while(cin.fail() || cin.peek() != '\n' && x > y) {
        fflush(stdin);
        cin.clear();
        cout << "Retry:" << endl;
        cin >> x;
    }
}


