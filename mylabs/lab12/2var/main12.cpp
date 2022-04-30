/*Создайте класс Complex для выполнения арифметических операций с комплексными числами*/

#include <iostream>
#include "lab12.h"
using namespace std;

int main() {
    

    int r1, i1, r2, i2;
    float res_r, res_i;

    cout << "Enter the real part of the first complex number:";
    cin >> r1;

    cout << "Enter the imaginary part of the first complex number:";
    cin >> i1;
    cout << endl;

    cout << "Enter the real part of the second complex number:";
    cin >> r2;

    cout << "Enter the imaginary part of the first complex number:";
    cin >> i2;
    cout << endl;
    
    Complex numbers(r1, r2, i1, i2);

    // numbers.setComplex(r1, r2, i1, i2);

    cout << "Initial numbers:" << endl;
    numbers.printComplex();
    cout << endl;

    cout << "After addition:" << endl;
    numbers.sumComplex();
    numbers.printResComplex();
    cout << endl;

    cout << "After subtraction:" << endl;
    numbers.subComplex();
    numbers.printResComplex();
    cout << endl;

    cout << "After multiplication:" << endl;
    numbers.multComplex();
    numbers.printResComplex();
    cout << endl;

    cout << "After division:" << endl;
    numbers.divComplex();
    numbers.printResComplex();
    cout << endl;

    return 0;
}