// Написать функции сложения, вычитания и умножения полиномов и тестирующую программу к ним.

#include "lab09.h"
#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
    node* top_polinom1, * end_polinom1;
    node* top_polinom2, * end_polinom2;
    node* temp_poly_top, * temp_poly_end;
    node* top_polinom3, * end_polinom3;
    node* top_polinom4, * end_polinom4;

    int n, n1, n2;

    cout << "1st: enter n = ";
    cin >> n1;
    cout << "\n";
    create_polinom(top_polinom1, end_polinom1, n1);

    cout << "2nd: enter n = ";
    cin >> n2;
    cout << "\n";
    create_polinom(top_polinom2, end_polinom2, n2);

    cout << "Choose operation:\n1 - summ\n2 - rasnost'\n3 - Umnozeniye\n";
    cin >> n;
    cout << "\n";

    int changed = 0;
    if (n2 > n1)
    {
        temp_poly_top = top_polinom2;
        temp_poly_end = end_polinom2;

        top_polinom2 = top_polinom1;
        end_polinom2 = end_polinom1;

        top_polinom1 = temp_poly_top;
        end_polinom1 = temp_poly_end;
        changed = 1;
    }

    sumn(top_polinom1, top_polinom2, top_polinom3, end_polinom3, top_polinom4, end_polinom4,n, changed, n1 + n2 - 2);
    printf_poly(top_polinom3);

    printf("\n");
    return 0;
}