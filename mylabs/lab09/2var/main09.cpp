//

#include "lab09.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void addToPoly(node *&top, node *&end, int power, int koef, int counter_nnode)
{
    // cout << "counter node: " << counter_nnode;
    node *p = new node;
    p->power = power;
    p->koef = koef;
    if (counter_nnode == 0)
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

void sumn(node *&top1, node *&top2, node *&top3, node *&end3)
{
    node *temp1 = top1;
    int counter_nnode = 0;
    node *p;
    while (1)
    {
        if (temp1 == NULL)
        {
            addToPoly(top3, end3, temp1->power, temp1->koef, counter_nnode);
            counter_nnode++;
            break;
        }
        node *temp2 = top2;
        while (1)
        {
            if (temp2 == NULL)
                break;
            if (temp1->power == temp2->power)
            {
                int t_power = temp1->power;
                int t_koef = temp1->koef + temp2->koef;
                addToPoly(top3, end3, t_power, t_koef, counter_nnode);
                counter_nnode++;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void printf_poly(node *&top3)
{
    node *poly = top3;
    while (1)
    {
        if (poly == NULL)
            break;
        cout << (poly->koef > 0 ? " +" : " ") << poly->koef;
        if (poly->power != 0)
            cout << "(x^" << poly->power << ")";
        poly = poly->next;
    }
}

int main()
{
    node *top_polinom1, *end_polinom1;
    node *top_polinom2, *end_polinom2;
    node *top_polinom3, *end_polinom3;

    int n;

    cout << "1st: enter n = ";
    cin >> n;
    cout << "\n";
    create_polinom(top_polinom1, end_polinom1, n);

    cout << "2nd: enter n = ";
    cin >> n;
    cout << "\n";
    create_polinom(top_polinom2, end_polinom2, n);

    cout << "Choose operation:\n1 - summ\n2 - rasnost'\n3 - Umnozeniye\n4 - Delenye\n";
    cin >> n;
    cout << "\n";
    switch (n)
    {
    case 1:
        sumn(top_polinom1, top_polinom2, top_polinom3, end_polinom3);
        printf_poly(top_polinom3);
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;

    default:
        cout << "Error number!";
        break;
    }

    return 0;
}