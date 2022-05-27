#include <iostream>
#include <math.h>
#define N 18
#define D 11
#include "List/List.h"
using namespace std;

uint64 count_ones(uint64 n) {
    uint64 w = 0;
    while (n > 0) {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}
// Исходными данными программы является N - максимальная длина кода, D - минимальное расстояние кода. 
int main()
{  
    size_t M = 0; // заводим счётчик числа кодовых слов в книге
    uint64 size = pow(2, N);
    uint64 mark[size] = { 0 }; // создаём вспомогательный массив для пометок заполненный 0
    uint64 CodeBook[size] = { 0 }; // Заводим массив для списка кодовых слов с запасом.

    List fl(size);

    uint64 zero;
    Node* t_next;
    Node* curNode;
    clock_t t1 = clock();
    while (fl.size > 0)
    {
        // -------------------------------------------------
        zero = fl.head->x;
        CodeBook[M] = zero;
        fl.rm_first();
        M++;
        
        for (curNode = fl.head; curNode != NULL; curNode = t_next)
        {
            t_next = curNode->next;
            if (count_ones(curNode->x ^ CodeBook[M - 1]) < D)
                fl.rm_by_node(curNode);
        }
    }

    // cout << "Answers: ";
    // for (size_t i = 0; i < M; i++) cout << CodeBook[i] << " ";
    // cout << endl << M << endl;
    clock_t t2 = clock();
    time_t duration = (t2 - t1);
    cout << endl << "Duration: "<< duration << endl;
    return 0;
}