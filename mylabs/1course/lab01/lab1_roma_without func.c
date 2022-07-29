#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    for (int minN = 2; minN < N; minN++)
    {

        int has_dels = 0;
        for (int i = 2; i < minN; i++)
            if (minN % i == 0)
                has_dels = 1;

        if (has_dels == 0)
            printf("Prostoe: %d\n", minN);
    }

    return 0;
}