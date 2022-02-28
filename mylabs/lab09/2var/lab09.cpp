#include <iostream>
#include <math.h>
using namespace std;

struct node
{
    // x * x - 9 * x + 14
    int koef;  // 1, -9, 14
    int power; // 2, 1, 0
    node *next;
};


void create_polinom(node *&top, node *&end, int n)
{
    int i;
    node *p;
    top = NULL;
    end = NULL;
    for (i = 0; i < n; i++)
    {
        p = new node;
        cout << " enter koef=";
        cin >> p->koef;
        cout << " enter power=";
        cin >> p->power;
        cout << "\n";
        if (i == 0)
        {
            p->next = top;
            top = p;
            end = p;
        }
        else
        {
            end->next = p;
            p->next = NULL;
            end = p;
        }
    }
}

double F2(node *&top, double x)
{
    double result = 0;
    node * cur = top;
    while (1){
        if (cur == NULL) break;
        result += cur->koef * pow(x, cur->power);
        cur = cur->next;
    }
    return result;
}

double FindRoot(double (*f)(node*&, double), double a, double b, double eps, node *&top)
{
    double c;
    while ((b - a) / 2 > eps)
    {
        c = (a + b) / 2;
        if ((f(top, a) * f(top, c)) > 0)
            a = c;
        else
            b = c;
    }
    return c;
}