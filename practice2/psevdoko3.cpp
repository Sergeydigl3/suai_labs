#include <iostream>
#include <math.h>
#define N 5
#define D 3
typedef unsigned long long uint64;
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

    
    uint64 zero=0;

    while (1) // выолняем шаги в цикле до тех пор пока нули находятся в пределах длины: 
    { 
        // -------------------------------------------------
        for (zero = 0; (mark[zero] != 0 && zero<size); zero++); // Шаг 0 выполняем поиск первой свободной последовательности в массиве mark, записываем в zero
        if (zero>=size) break; // Если Шаг 0 перебрал все элементы выходим из 
        CodeBook[M] = zero; // Шаг 1 Выберем в качестве кодового слова первую свободную последовательнотсть        
        mark[zero] = 2;
        M++;

        for (uint64 i = 0; i < size;i++)
        {
            if (mark[i] == 0 && (count_ones(i ^ CodeBook[M - 1]) < D))
                mark[i] = 1;

            cout << mark[i] << " ";
        }
        cout << endl;
    }

    cout << "Answers: ";
    for (size_t i = 0; i < M; i++) cout << CodeBook[i] << " ";
    cout << endl << M << endl;

    return 0;
}