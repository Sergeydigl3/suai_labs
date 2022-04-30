#include <iostream>
#include "lab12.h"
#include <math.h>
using namespace std;

Complex::Complex(int r1, int r2, int i1, int i2) {

    setComplex(r1, r2, i1, i2);

}

void Complex::setComplex(int r1, int r2, int i1, int i2) {
    p_r1 = r1;
    p_r2 = r2;

    p_i1 = i1;
    p_i2 = i2;
}

void Complex::sumComplex() {
    res_r = p_r1 + p_r2;
    res_i = p_i1 + p_i2;
}

void Complex::subComplex() {
    res_r = p_r1 - p_r2;
    res_i = p_i1 - p_i2;
}

void Complex::printResComplex() {
    if (res_i >= 0) cout << "z=" << res_r << "+" << res_i << "*i" << endl;
    else cout << "z=" << res_r << res_i << "*i" << endl;
}

void Complex::printComplex() {
    if (p_i1 >= 0) cout << "z1=" << p_r1 << "+" << p_i1 << "*i" << endl;
    else cout << "z1=" << p_r1 << p_i1 << "*i" << endl;
    if (p_i2 >= 0) cout << "z2=" << p_r2 << "+" << p_i2 << "*i" << endl;
    else cout << "z2=" << p_r2 << p_i2 << "*i" << endl;
}

void Complex::multComplex() {
    res_r = (p_r1 * p_r2) - (p_i1 * p_i2);
    res_i = (p_r1 * p_i2) + (p_i1 * p_r2);
}

void Complex::divComplex() {
    res_r = float(p_r1 * p_r2 + p_i1 * p_i2) / float(p_r2 * p_r2 + p_i2 * p_i2);
    res_i = float(p_r2 * p_i1 - p_r1 * p_i2) / float(p_r2 * p_r2 + p_i2 * p_i2);
}