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

void sumn(node *&top1, node *&top2, node *&top3, node *&end3, int act)
{
    node *temp1 = top1;
    int counter_nnode = 0;
    node *p;
    while (1)
    {
        if (temp1 == NULL)
        {
            break;
        }
        node *temp2 = top2;
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
                    t_koef = temp1->koef - temp2->koef;
                    break;
                    
                case 3: // umnoj
                    t_koef = temp1->koef * temp2->koef;
                    break;
                
                case 4: // del
                    t_koef = temp1->koef / temp2->koef;

                default:
                    break;
                }
                
                addToPoly(top3, end3, t_power, t_koef, counter_nnode);
                counter_nnode++;
                found = 1;
            }
            temp2 = temp2->next;
        }
        if (found == 0) {addToPoly(top3, end3, temp1->power, temp1->koef, counter_nnode);counter_nnode++;}
        temp1 = temp1->next;
    }
}

void printf_poly(node *&top3)
{
    node *poly = top3;
    int first = 1;
    cout << "Result: ";
    while (1)
    {
        if (poly == NULL)
            break;
        if (first == 1) {cout << poly->koef; first=0;}
        else cout << (poly->koef > 0 ? " +" : " ") << poly->koef;
        if (poly->power != 0)
            if (poly->power == 1)
                cout << "x";
            else
                cout << "(x^" << poly->power << ")";
        poly = poly->next;
    }
}

int main()
{
    node *top_polinom1, *end_polinom1;
    node *top_polinom2, *end_polinom2;
    node *temp_poly_top, *temp_poly_end;
    node *top_polinom3, *end_polinom3;

    int n, n1, n2;

    cout << "1st: enter n = ";
    cin >> n1;
    cout << "\n";
    create_polinom(top_polinom1, end_polinom1, n1);

    cout << "2nd: enter n = ";
    cin >> n2;
    cout << "\n";
    create_polinom(top_polinom2, end_polinom2, n2);

    cout << "Choose operation:\n1 - summ\n2 - rasnost'\n3 - Umnozeniye\n4 - Delenye\n";
    cin >> n;
    cout << "\n";

    if (n2>n1){
        temp_poly_top = top_polinom2;
        temp_poly_end = end_polinom2;

        top_polinom2 = top_polinom1;
        end_polinom2 = end_polinom1;

        top_polinom1 = temp_poly_top;
        end_polinom1 = temp_poly_end;
    }


    sumn(top_polinom1, top_polinom2, top_polinom3, end_polinom3, n);   

    printf("\n");
    return 0;
}