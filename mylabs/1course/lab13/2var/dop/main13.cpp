#include <iostream>
#include "lab13.h"
using namespace std;

// TODO: Доп Сделать класс день родждения который будет уноследован от Даты. 
// Поля: Год, месяц, дни
// В конструктор аргумент (сколько дней человек прожил). Высчитывается год рождения от текущей.
// Перегрузка разности, между людьми, сеттеры гетеры


int main() {
    Birthday Sergey(6874);
    cout << Sergey << endl;
    Birthday Den;
    cin >> Den;
    cout << endl << (Den>Sergey);


    // cout << "Sum: " << d1 + d2 << endl;
    cout << endl;
}