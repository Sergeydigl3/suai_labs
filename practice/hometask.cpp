#include <stdio.h>
#define count 256
int counter(int data)
{
    int x = 1, w = 0;
    x = data;
    while (x > 0)
    {
        w = w + (x & 1);
        x = x >> 1;
    }

    return w;
}

char arr[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
int counter2(int data)
{
    int x = 1, w = 0;
    x = data;
    while (x > 0)
    {
        w = w + arr[x & 15];
        x = x >> 4;
    }

    return w;
}


int main(int argc, char *argv[])
{
    // int mass[count];
    int mass[9]={0};
    for (int i = 0; i < count; i++)
    {
        mass[counter2(i)]++;
    }
    printf("\n");

    for (size_t i = 0; i < 9; i++)
    {
        printf("%ld - %d\n", i, mass[i]);
    }
    return 0;
}