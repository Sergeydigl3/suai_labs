#include <iostream>
#include "lab12.h"
#include <math.h>
using namespace std;


Complex::Complex(double re, double im) {
    this->re = re; this->im = im;
}

Complex::Complex() : re(0) , im(0) { }

void Complex::set_re(double re) { this->re = re; }

void Complex::set_im(double re) { this->re = re; }

double Complex::get_re() { return this->re; }

double Complex::get_im() { return this->im; }

Complex Complex :: operator+( const Complex & c ){
    Complex ret;
    ret.re = this->re + c.re;
    ret.im = this->im + c.im;
    return ret;
};

Complex Complex :: operator-( const Complex & c ){
    Complex ret;
    ret.re = this->re - c.re;
    ret.im = this->im - c.im;
    return ret;
};

Complex Complex :: operator*( const Complex & c ){
    Complex ret;
    ret.re = (this->re * c.re) - (this->im * c.im);
    ret.im = (this->re * c.im) + (this->im * c.re);
    return ret;
};

Complex Complex :: operator/( const Complex & c ){
    Complex ret;
    ret.re = float(this->re * c.re + this->im * c.im) / float(c.re * c.re + c.im * c.im);
    ret.im = float(c.re * this->im - this->re * c.im) / float(c.re * c.re + c.im * c.im);
    return ret;
};

void Complex :: printComplex() {
    if (this->im >= 0) cout << "z=" << this->re << "+" << this->im << "*i" << endl;
    else cout << "z=" << this->re << this->im << "*i" << endl;
}


// Complex Complex::add(const Complex& c) {
//     Complex ret;
//     ret.re = re + c.re;
//     ret.im = im + c.im;
//     return ret;
// }



// Complex::Complex(int r1, int r2, int i1, int i2) {

//     setComplex(r1, r2, i1, i2);

// }

// void Complex::setComplex(int r1, int r2, int i1, int i2) {
//     p_r1 = r1;
//     p_r2 = r2;

//     p_i1 = i1;
//     p_i2 = i2;
// }

// void Complex::sumComplex() {
//     res_r = p_r1 + p_r2;
//     res_i = p_i1 + p_i2;
// }

// void Complex::subComplex() {
//     res_r = p_r1 - p_r2;
//     res_i = p_i1 - p_i2;
// }

// void Complex::printResComplex() {
//     if (res_i >= 0) cout << "z=" << res_r << "+" << res_i << "*i" << endl;
//     else cout << "z=" << res_r << res_i << "*i" << endl;
// }

// void Complex::printComplex() {
//     if (p_i1 >= 0) cout << "z1=" << p_r1 << "+" << p_i1 << "*i" << endl;
//     else cout << "z1=" << p_r1 << p_i1 << "*i" << endl;
//     if (p_i2 >= 0) cout << "z2=" << p_r2 << "+" << p_i2 << "*i" << endl;
//     else cout << "z2=" << p_r2 << p_i2 << "*i" << endl;
// }

// void Complex::multComplex() {
//     res_r = (p_r1 * p_r2) - (p_i1 * p_i2);
//     res_i = (p_r1 * p_i2) + (p_i1 * p_r2);
// }

// void Complex::divComplex() {
//     res_r = float(p_r1 * p_r2 + p_i1 * p_i2) / float(p_r2 * p_r2 + p_i2 * p_i2);
//     res_i = float(p_r2 * p_i1 - p_r1 * p_i2) / float(p_r2 * p_r2 + p_i2 * p_i2);
// }