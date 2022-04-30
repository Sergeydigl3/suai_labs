/*Создайте класс Complex для выполнения арифметических операций с комплексными числами*/
// Доп: сделать доп класс вектор комплексных чисел, set, get, правило 3ёх, сумма векторов(индекс к индексу)
#include <iostream>
#include "lab12.h"
using namespace std;

int main() {
    double r1, i1, r2, i2;

    cout << "Enter the real part of the first complex number:";
    cin >> r1;

    cout << "Enter the imaginary part of the first complex number:";
    cin >> i1;
    Complex c1 (r1 , i1);
    cout << endl;

    cout << "Enter the real part of the second complex number:";
    cin >> r2;

    cout << "Enter the imaginary part of the first complex number:";
    cin >> i2;
    Complex c2 (r2 , i2);
    cout << endl;

    cout << "Initial numbers:" << endl;
    c1.printComplex();
    c2.printComplex();
    cout << endl;

    cout << "After addition:" << endl;
    (c1+c2).printComplex();
    cout << endl;

    cout << "After subtraction:" << endl;
    (c1-c2).printComplex();
    cout << endl;

    cout << "After multiplication:" << endl;
    (c1*c2).printComplex();
    cout << endl;

    cout << "After division:" << endl;
    (c1/c2).printComplex();
    cout << endl;

    return 0;
}