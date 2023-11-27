#include "Lab1.h"



//������� ����� employee. ����� ������ ������� ���� int ��� �࠭����
//����� ���㤭��� � ���� float ��� �࠭���� ����稭� ��� ������. �������
//ᮤ�ঠ��� ����� employee, ����稢 � ���� ����� date � ����᫥��� etype.
//��ꥪ� ����� date �ᯮ�짮���� ��� �࠭���� ���� �ਥ�� ���㤭��� ��
//ࠡ���. ����᫥��� �ᯮ�짮���� ��� �࠭���� ����� ���㤭���:
//����࠭�, ᥪ����, �������� � �. �. ���ࠡ���� ��⮤� getemploy() �
//putemploy(), �।�����祭�� ᮮ⢥��⢥��� ��� ����� � �⮡ࠦ����
//���ଠ樨 � ���㤭���. ������� �ணࠬ��, ����� �㤥� �뤠����
//ᢥ����� � ���㤭����.

//�������� �஢��� �� �����(䥢ࠫ� 29 ����) + �������� ������� + �뭥�� ������� �㭪樨 �⤥�쭮

//������� �����, ����ᠭ�� �� �믮������ ������୮� ࠡ��� �1,
//������� � ���� ��ॣ�㧪� �㭪権, �����஢ + � &(��������� �� ��� �롮�).
//������� ����� ��� ࠡ��� � ᨬ����묨 ��ப���. ������ ��� ��ப�
//�⢮���� �������᪨. ��ॣ�㧨�� �������


// ��।������ ����� date
class date {
public:
    int year;
    int month;
    int day;
};

// ��।������ ����� employee
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


    // ��⮤ ��� ����� ���ଠ樨 � ���㤭���
    void putEmploy(float money_t, int year_t, int month_t, int day_t) {
        money = money_t;
        date.year = year_t;
        date.month = month_t;
        date.day = day_t;
        eType prof;

        cout << "Choice work: \n 0 - laborer\n 1 - secretary\n 2 - manager\n3 - director" << endl;
        int checking;
        cin >> checking;

        // �஢�ઠ ���४⭮�� ����� ⨯� ���㤭���
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

    // ��⮤ ��� �뢮�� ���ଠ樨 � ���㤭���
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


// ���� ������ � ���㤭���
void getDMY(employee* User)
{
    float money_t;
    cout << "Put money:" << endl;
    cin >> money_t;
    while(cin.fail() || cin.peek() != '\n') {
        fflush(stdin);
        cin.clear();
        cout << "Retry:" << endl;
        cin >> money_t;
    }

    cout << "Put year:" << endl;
    int year_t;
    cin >> year_t;
    check(year_t);

    cout << "Put Month:" << endl;
    int month_t;
    cin >> month_t;
    while(cin.fail() || cin.peek() != '\n' || month_t > 12) {
        fflush(stdin);
        cin.clear();
        cout << "Retry:" << endl;
        cin >> month_t;
    }

    cout << "Put Day:" << endl;
    int day_t;
    cin >> day_t;

    while(cin.fail() || cin.peek() != '\n' || day_t >= 28) {
        int x = month_check(month_t, day_t);
        if(x == 1)
            break;
        fflush(stdin);
        cin.clear();
        cout << "Retry:" << endl;
        cin >> day_t;
    }
    User->putEmploy(money_t, year_t, month_t, day_t);
}


int main() {
    cout << "How many employees?" << endl;
    int number;
    cin >> number;
    check(number - 1);

    // �������� ���ᨢ� ���㤭����
    auto *employees = new employee[number];

    // ���� ������ � ���㤭����
    for(int i = 0; i < number; i++)
    {
        getDMY(&employees[i]);
    }

    cout << "Enter the number of the user you want to see\n0 - output of all added users\n-1 - to exit the program" << endl;
    int user;
    int salary = 0;
    for(int i = 0; i < number; i++) {
        salary += employees[i] + employees[i+1];
        salary -= employees[i+1].getMoney();
    }
    cin >> user;
    check(user, number);
    while(true) {
        if (user == 0) {
            for (int i = 0; i < number; i++)
                employees[i].getEmploy(i + 1);
            cout << "Total Salary: " << salary << endl;
        }
        else if(user == -1)
        {
            break;
        }
        else {
            if(user > number || user < -1)
                cout << "Retry" << endl;
            else
                employees[user - 1].getEmploy(user);
        }
        fflush(stdin);
        cin.clear();
        cin >> user;
        check(user, number);
    }

    // �᢮�������� �����
    delete [] employees;
}
