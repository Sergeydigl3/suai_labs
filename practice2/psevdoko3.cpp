#include <iostream>
#include <math.h>
#define N 5
#define D 3

using namespace std;

unsigned long long count_ones(unsigned long long n) {
    unsigned long long w = 0;
    while (n > 0) {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}
// Исходными данными программы является N - максимальная длина кода, D - минимальное расстояние кода. 
int main()
{
    int M = 0;// заводим счётчик числа кодовых слов в книге
    unsigned long long size = pow(2, N); 
    int mark[size] = { 0 }; // создаём вспомогательный массив для пометок заполненный 0
    unsigned long long CodeBook[size] = { 0 }; // Заводим массив для списка кодовых слов с запасом.

    
    unsigned long long zero=0;

    while (zero<size) // выолняем шаги в цикле до тех пор пока нули находятся в пределах длины: 
    { 
        // -------------------------------------------------
        for (zero = 0; (mark[zero] != 0 && zero<size); zero++);
        CodeBook[M] = zero; // Шаг 1 Выберем в качестве кодового слова первую свободную последовательнотсть        mark[zero] = 2;
        M++;

        for (unsigned long long i = 0; i < size;i++)
        {
            if (mark[i] == 0 && (count_ones(i ^ CodeBook[M - 1]) < D))
            {
                mark[i] = 1;

            }
            cout << mark[i] << " ";
        }
        //for (zero = 0; (mark[zero] != 0 && zero<size); zero++);
        cout << endl;
    }

    cout << "Answers: ";
    for (size_t i = 0; i < M; i++) cout << CodeBook[i] << " ";
    cout << endl;

    return 0;
}