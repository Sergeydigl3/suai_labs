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
    Complex operator+( const Complex & c );
    Complex operator-( const Complex & c );
    Complex operator*( const Complex & c );
    Complex operator/( const Complex & c );

    void printComplex();
};


class ComplexVector {
    // ComplexVector();
    void append(Complex comp);
    void set(Complex comp, size_t index);
    Complex get(size_t index);
    ComplexVector operator+(ComplexVector & c );
    // ComplexVector operator-( const ComplexVector & c );
    // ComplexVector operator*( const ComplexVector & c );
    // ComplexVector operator/( const ComplexVector & c );

private:
    vector <Complex> array;
};