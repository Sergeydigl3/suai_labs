#include <iostream>
#include <math.h>

using namespace std;

double f(double x) { return (cos(x)); }
double I(double a, double b, int n, double y) { return ((b - a) / (2 * n) * y); }

double smth_do(double a, double b, double n)
{
    double y, dy, In;
    dy = (b - a) / n;
    y = f(a) + f(b);
    for (int i = 1; i < n; i++)
    {
        y += 2 * (f(a + dy * i));
    }
    In = I(a, b, n, y);
    return In;
}