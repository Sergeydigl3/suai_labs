#include <stdio.h>

int fibon(int x)
{
    if (x < 2)
        return x;
    else
        return fibon(x - 1) + fibon(x - 2);
}

int main()
{
    int x = 0;
    int i = 0;
    while (x < 1000)
    {
        x = fibon(i);
        i++;
    }
    printf("%d", x);
    return 0;
}