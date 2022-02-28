#pragma once

struct node
{
    // x * x - 9 * x + 14
    int koef;  // 1, -9, 14
    int power; // 2, 1, 0
    node *next;
};

void create_polinom(node *&top, node *&end, int n);

double F2(node *&top, double x);

double FindRoot(double (*f)(node*&, double), double a, double b, double eps, node *&top);