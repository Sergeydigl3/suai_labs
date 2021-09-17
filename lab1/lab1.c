#include <stdio.h>

int main()
{
    int x, maxx = 0;
    while (1)
    {
        scanf_s("%d", &x);

        if (x == 0)
            break;
        else
        {
            if (x > maxx || maxx == 0)
                maxx = x;
        };
    }
    printf("%d", maxx);
    return 0;
}