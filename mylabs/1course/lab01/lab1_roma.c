#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for (int minN = 2; minN < N; minN++)
    {
        if (has_dels(minN) == 0)
            printf("Prostoe: %d\n", minN);
    }

    return 0;
}

// 1 - Has dels
// 0 - No dels
int has_dels(int x)
{
    for (int i = 2; i < x; i++)
        if (x % i == 0)
            return 1;

    return 0;
}