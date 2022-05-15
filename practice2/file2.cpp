#include <stdio.h>
#include <math.h>
#define N 5
#define D 3

unsigned char count_ones(unsigned char n) {
    unsigned char w = 0;
    while (n > 0) {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}

// void brutforce(in)


int main()
{
    int M = 0;
    int size = pow(2, N);
    int mark[size] = { 0 };
    int CodeBook[size] = { 0 };

    int zero = 0;
    
    while (zero<size)
    { 
        CodeBook[M] = zero;
        mark[zero] = 2;
        M++;

        for (int i = 0; i < size;i++)
        {
            if (mark[i] == 0 && (count_ones(i ^ CodeBook[M - 1]) < D))
            {
                mark[i] = 1;

            }
            printf("%d ", mark[i]);
        }
        for (zero = 0; (mark[zero] != 0 && zero<size); zero++);
        printf("\n");
    }

    printf("\n%d,%d,%d", CodeBook[0], CodeBook[1], CodeBook[2]);


    return 0;
}