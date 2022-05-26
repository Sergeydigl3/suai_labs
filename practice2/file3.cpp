typedef unsigned long long uint64;

#include <iostream>
#include <math.h>
#define N 5
#define D 3

using namespace std;

uint64 count_ones(uint64 n) {
    uint64 w = 0;
    while (n > 0) {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}

string str_bin(uint64 n, uint64 size) {
    string ret_str;
    for (unsigned char i = 0; i < size; i++)
        ret_str += to_string((n >> (size - 1 - i)) & 1);
    return ret_str;
}

int main()
{
    unsigned int M = 0;
    uint64 size = pow(2, N);
    uint64 mark[size] = { 0 };
    uint64 CodeBook[size] = { 0 };

    uint64 zero = 0;
    
    while (zero<size)
    { 
        CodeBook[M] = zero;
        mark[zero] = 2;
        M++;

        for (uint64 i = 0; i < size;i++)
        {
            if (mark[i] == 0 && (count_ones(i ^ CodeBook[M - 1]) < D))
            {
                mark[i] = 1;

            }
            cout << mark[i] << " ";
        }
        for (zero = 0; (mark[zero] != 0 && zero<size); zero++);
        cout << endl;
    }

    cout << "Answers: " << endl;
    for (size_t i = 0; i < M; i++) cout << str_bin(CodeBook[i], N) << " " << CodeBook[i] << endl;
    cout << endl << endl << M << endl;

    return 0;
}