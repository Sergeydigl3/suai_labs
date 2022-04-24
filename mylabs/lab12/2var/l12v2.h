/*Создайте класс Complex для выполнения арифметических операций с комплексными числами*/

// z1 = r1+i1*i
// z2 = r2+i2*i

#pragma once

#include <iostream>

class Complex {

private:

int p_r1, p_i1, p_r2, p_i2;
float res_r, res_i;

public:

Complex();

void setComplex(int r1, int r2, int i1, int i2);

void sumComplex();

void subComplex();

void multComplex();

void divComplex();

void printResComplex();

void printComplex();

};