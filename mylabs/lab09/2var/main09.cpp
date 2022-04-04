// Написать функции сложения, вычитания и умножения полиномов и тестирующую программу к ним.

#include "lab09.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void printf_poly(node*& top3)
{
    node* poly = top3;
    int first = 1;
    cout << "Result: ";
    while (1)
    {
        if (poly == NULL)
            break;
        if (first == 1)
        {
            cout << poly->koef;
            first = 0;
        }
        else
            cout << (poly->koef >= 0 ? " +" : " ") << poly->koef;
        if (poly->power != 0)
            if (poly->power == 1)
                cout << "x";
            else
                cout << "(x^" << poly->power << ")";
        poly = poly->next;
    }
}


void addToPoly(node*& top, node*& end, int power, int koef, int counter_nnode)
{
    // cout << "counter node: " << counter_nnode;
    node* p = new node;
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

void sumn(node*& top1, node*& top2, node*& top3, node*& end3, node*& top4, node*& end4, int act, int changed, int maxpower)
{
    if (act == 3)
    {
        node* temp1 = top1;
        int counter_nnode = 0;
        node* p;
        while (1)
        {
            if (temp1 == NULL)
            {
                break;
            }
            node* temp2 = top2;
            int found = 0;
            while (1)
            {
                if (temp2 == NULL)
                    break;

                addToPoly(top4, end4, temp1->power + temp2->power, temp1->koef * temp2->koef, counter_nnode);
                counter_nnode++;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        printf_poly(top4);
        printf("\n");
        counter_nnode = 0;
        for (int i = maxpower; i > -1; i--)
        {
            node* temp1 = top4;
            node* p;
            int t_koef = 0;
            while (1)
            {
                if (temp1 == NULL)
                {
                    break;
                }
                if (temp1->power == i)
                    t_koef+=temp1->koef;
                temp1 = temp1->next;
            }
            addToPoly(top3, end3, i, t_koef, counter_nnode);
            counter_nnode++;
        }
    }
    else
    {
        node* temp1 = top1;
        int counter_nnode = 0;
        node* p;
        while (1)
        {
            if (temp1 == NULL)
            {
                break;
            }
            node* temp2 = top2;
            int found = 0;
            while (1)
            {
                if (temp2 == NULL)
                    break;
                if (temp1->power == temp2->power)
                {
                    int t_power = temp1->power;
                    int t_koef;
                    switch (act)
                    {
                    case 1: // summa
                        t_koef = temp1->koef + temp2->koef;
                        break;

                    case 2: // razn
                        if (changed == 1)
                            t_koef = temp2->koef - temp1->koef;
                        else
                            t_koef = temp1->koef - temp2->koef;
                        break;

                    default:
                        break;
                    }

                    addToPoly(top3, end3, t_power, t_koef, counter_nnode);
                    counter_nnode++;
                    found = 1;
                }
                temp2 = temp2->next;
            }
            if (found == 0)
            {
                if (act == 2 && changed == 1)
                    addToPoly(top3, end3, temp1->power, -(temp1->koef), counter_nnode);
                else
                    addToPoly(top3, end3, temp1->power, temp1->koef, counter_nnode);
                counter_nnode++;
            }
            temp1 = temp1->next;
        }
    }
}


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