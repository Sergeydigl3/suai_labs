#pragma once

struct node
{
    // x * x - 9 * x + 14
    int koef;  // 1, -9, 14
    int power; // 2, 1, 0
    node *next;
};

void create_polinom(node *&top, node *&end, int n);

void printf_poly(node*& top3);


void addToPoly(node*& top, node*& end, int power, int koef, int counter_nnode);


void sumn(node*& top1, node*& top2, node*& top3, node*& end3, node*& top4, node*& end4, int act, int changed, int maxpower);