#include <iostream>
#include "lab12.h"
#include <math.h>
#include <cstdlib>
using namespace std;



Complex::Complex(double re, double im) {
    this->re = re; this->im = im;
}

Complex::Complex() : re(0), im(0) { }

void Complex::enter_data() {
    cout << "Enter the real part of the first complex number:";
    cin >> this->re;

    cout << "Enter the imaginary part of the first complex number:";
    cin >> this->im;
    cout << endl;
}

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

size_t ComplexVector::size() { return this->array.size(); }

void ComplexVector::print() {
    for (size_t i = 0; i < this->array.size(); i++)
    {
        cout << i << ": ";
        this->array[i].printComplex();
    }

}

void ComplexVector::push(Complex comp) {
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

Complex ComplexVector::sub_operation(size_t action, Complex& c1, Complex& c2) {
    switch (action)
    {
    case 0:
        return c1 + c2;
        break;
    case 1:
        return c1 - c2;
        break;
    case 2:
        return c1 * c2;
        break;
    case 3:
        return c1 / c2;
        break;

    default:
        return c1 + c2;
        break;
    }
}

ComplexVector ComplexVector::do_operation(size_t action, ComplexVector& c) {
    size_t s1 = this->array.size();
    size_t s2 = c.array.size();
    size_t max_size = max(s1, s2);
    size_t min_size = min(s1, s2);

    ComplexVector complexvector_t;
    for (size_t i = 0; i < max_size; i++)
    {
        if (i >= min_size)
            if (s1 > s2)
                complexvector_t.push(
                    this->array[i]
                );
            else
                complexvector_t.push(
                    c.array[i]
                );
        else
            complexvector_t.push(
                sub_operation(action, this->array[i], c.array[i])
            );
    }
    return complexvector_t;
}

ComplexVector ComplexVector :: operator+(ComplexVector& c) {
    return do_operation(0, c);
}
ComplexVector ComplexVector :: operator-(ComplexVector& c) {
    return do_operation(1, c);
}
ComplexVector ComplexVector :: operator*(ComplexVector& c) {
    return do_operation(2, c);
}
ComplexVector ComplexVector :: operator/(ComplexVector& c) {
    return do_operation(3, c);
}