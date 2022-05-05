#include <iostream>
#include "lab12.h"
#include <math.h>
#include <cstdlib>
using namespace std;



Complex::Complex(double re, double im) {
    this->re = re; this->im = im;
}

Complex::Complex() : re(0), im(0) { }

void Complex::set_re(double re) { this->re = re; }

void Complex::set_im(double re) { this->re = re; }

double Complex::get_re() { return this->re; }

double Complex::get_im() { return this->im; }

Complex Complex :: operator+(const Complex& c) {
    Complex ret;
    ret.re = this->re + c.re;
    ret.im = this->im + c.im;
    return ret;
};

Complex Complex :: operator-(const Complex& c) {
    Complex ret;
    ret.re = this->re - c.re;
    ret.im = this->im - c.im;
    return ret;
};

Complex Complex :: operator*(const Complex& c) {
    Complex ret;
    ret.re = (this->re * c.re) - (this->im * c.im);
    ret.im = (this->re * c.im) + (this->im * c.re);
    return ret;
};

Complex Complex :: operator/(const Complex& c) {
    Complex ret;
    ret.re = float(this->re * c.re + this->im * c.im) / float(c.re * c.re + c.im * c.im);
    ret.im = float(c.re * this->im - this->re * c.im) / float(c.re * c.re + c.im * c.im);
    return ret;
};

void Complex::printComplex() {
    if (this->im >= 0) cout << "z=" << this->re << "+" << this->im << "*i" << endl;
    else cout << "z=" << this->re << this->im << "*i" << endl;
}



void ComplexVector::append(Complex comp) {
    this->array.push_back(comp);
}

void ComplexVector::set(Complex comp, size_t index) {
    if (index < this->array.size())
        this->array[index] = comp;
    else {
        cerr << "Wrong index in ComplexVector::set(" << index << ");" << endl;
        exit(1);
    }
}

Complex ComplexVector::get(size_t index) {
    if (index < this->array.size())
        return this->array[index];
    else {
        cerr << "Wrong index in ComplexVector::get(" << index << ");" << endl;
        exit(1);
    }
}

ComplexVector ComplexVector :: operator+(ComplexVector& c) {
    size_t min_size = min(this->array.size(), c.array.size());
    // size_t max_size = max(this->array.size(), c.array.size());
    ComplexVector complexvector_t;
    for (size_t i = 0; i < min_size; i++)
    {
        Complex temp (this->array[i].get_re()+c.array[i].get_re(), this->array[i].get_im()+c.array[i].get_im());
        complexvector_t.append(
            temp
        );
    }
    return complexvector_t;
}