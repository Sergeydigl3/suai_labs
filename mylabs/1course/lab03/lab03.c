#include <stdio.h>

void find_close(int mass[], int x, int size)
{
    int mindif = -1;
    int pos1 = -1;
    int pos2 = -1;

    for (int i = 0; i < size; i++)
    {
        int diff = abs(x - mass[i]);
        if (mindif == -1 || diff <= mindif)
        {
            if (diff == mindif)
                pos2 = i;
            else
                pos1 = i;
            mindif = diff;
        }
    }

    if (pos1 != -1)
        printf("Min x1: %d\n", mass[pos1]);
    if (pos2 != -1)
        printf("Min x2: %d\n", mass[pos2]);
}

int main(int argc, char const *argv[])
{
    int tmass[] = {4, 20, 34, 7};
    int size = 4;
    int x = 5;

    find_close(tmass, x, size);

    return 0;
}

int print_array(int x[], int len)
{
    int k;

    for (k = 0; k < len; k++)
    {
        printf("x[%d] = %d\n", k, x[k]);
    }
    return 0;
}

int abs(int x)
{
    if (x < 0)
        return x * (-1);
    return x;
}