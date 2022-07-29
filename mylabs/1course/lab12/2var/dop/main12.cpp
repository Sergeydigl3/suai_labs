/*Создайте класс Complex для выполнения арифметических операций с комплексными числами*/
// Доп: сделать доп класс вектор комплексных чисел, set, get, правило 3ёх, сумма векторов(индекс к индексу)
#include <iostream>
#include "lab12.h"
using namespace std;

int main() {
    Complex c1, c2, c3;
    c1.enter_data();
    c2.enter_data();
    c3.enter_data();

    ComplexVector d1, d2;
    d1.push(c1);
    d2.push(c2);
    d2.push(c3);

    cout << "Initial numbers:" << endl;
    d1.print();
    cout << endl;
    d2.print();
    cout << endl;

    cout << "After addition:" << endl;
    (d1 + d2).print();
    cout << endl;

    // d1.print();
    // d2.print();
    // d3.print();



    // cout << "After subtraction:" << endl;
    // (c1-c2).printComplex();
    // cout << endl;

    // cout << "After multiplication:" << endl;
    // (c1*c2).printComplex();
    // cout << endl;

    // cout << "After division:" << endl;
    // (c1/c2).printComplex();
    // cout << endl;

    return 0;
}