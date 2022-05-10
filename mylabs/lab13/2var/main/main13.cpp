#include <iostream>
#include "lab13.h"
using namespace std;

// TODO: Доп Сделать класс день родждения который будет уноследован от Даты. 
// Поля: Год, месяц, дни
// В конструктор аргумент (сколько дней человек прожил). Высчитывается год рождения от текущей.
// Перегрузка разности, между людьми, сеттеры гетеры


int main() {

    Date d1 = Date(30) + Date(12);
    Date d2 = Date(12) + 32;
    cout << "Inital d1: Date->days = " << d1.get_days() << endl;
    cout << "Inital d2: Date->days = " << d2.get_days() << endl;
    d1++;
    d2--;
    cout << "d1 after oper++: " << d1.get_days()<<endl;
    cout << "d2 after oper--: " << d2.get_days()<<endl;


    cout << endl <<"Boolean check: " << endl;
    cout << "d1==d2: " << (d1 == d2) << endl;
    cout << "d1!=d2: " << (d1 != d2) << endl;
    cout << "d1>=d2: " << (d1 >= d2) << endl;
    cout << "d1<=d2: " << (d1 <= d2) << endl;
    cout << "d1>d2: " << (d1 > d2) << endl;
    cout << "d1<d2: " << (d1 < d2) << endl;

    cout << endl;
}