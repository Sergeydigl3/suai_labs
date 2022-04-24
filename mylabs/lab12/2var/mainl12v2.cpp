/*Создайте класс Complex для выполнения арифметических операций с комплексными числами*/

#include <iostream>
#include "l12v2.h"
using namespace std;

int main(){
    Complex numbers;

    cout<<"Initial numbers:"<<endl;
    numbers.printComplex();
    cout<<endl;

    cout<<"After addition:"<<endl;
    numbers.sumComplex();
    numbers.printResComplex();
    cout<<endl;

    cout<<"After subtraction:"<<endl;
    numbers.subComplex();
    numbers.printResComplex();
    cout<<endl;

    cout<<"After multiplication:"<<endl;
    numbers.multComplex();
    numbers.printResComplex();
    cout<<endl;

    cout<<"After division:"<<endl;
    numbers.divComplex();
    numbers.printResComplex();
    cout<<endl;

    return 0;
}