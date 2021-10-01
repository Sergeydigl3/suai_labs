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

void find_extr(int mass[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int prev = 0;
        int next = 0;
        if (i != 0)
            prev = mass[i - 1];
        if (i != len - 1)
            next = mass[i + 1];

        //more
        if (prev > mass[i] && next > mass[i])
            printf("%d\n", mass[i]);

        //lower
        if (prev < mass[i] && next < mass[i])
            printf("%d\n", mass[i]);
    }
}


int main(int argc, char const *argv[])
{
    int tmass[] = {4, 2, 6, 8, 7, 3, 3, 2, 2};
    int size = 9;

    find_extr(tmass, size);
    // find_close(tmass, x, size);

    // print_array(tmass,4);

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