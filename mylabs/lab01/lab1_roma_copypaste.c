#include <stdio.h>

int main()
{
    int N, prime = 2, div, i;

    printf("Enter N \n N=");
    scanf_s("%d", &N);

    while (prime < N)
    {
        div = 2;
        i = 1;

        while (div <= prime)
        {
            if (prime % div == 0)
            {
                i++;
            }
            div++;
        }

        if (i <= 2)
            printf("%d\n", prime);
        prime++;
    }
    return 0;
}