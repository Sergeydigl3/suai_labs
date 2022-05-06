// Создайте класс Complex для выполнения арифметических операций с комплексными числами

// z1 = r1+i1*i

#pragma once

#include <vector>
using namespace std;
class Complex {

private:
    double re;
    double im;

public:
    Complex();
    Complex(double re, double im);
    void set_re(double re);
    void set_im(double im);
    double get_re();
    double get_im();
    void enter_data();
    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);

    void printComplex();
};


class ComplexVector {
public:
    void push(Complex comp);
    void set(Complex comp, size_t index);
    void print();
    size_t size();
    Complex get(size_t index);
    ComplexVector operator+(ComplexVector& c);
    ComplexVector operator-(ComplexVector& c);
    ComplexVector operator*(ComplexVector& c);
    ComplexVector operator/(ComplexVector& c);

private:
    Complex sub_operation(size_t action, Complex& c1, Complex& c2);
    ComplexVector do_operation(size_t action, ComplexVector& c);
    vector <Complex> array;
};