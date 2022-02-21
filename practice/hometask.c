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
    // printf("%d", w);

    return w;
}

int main(int argc, char *argv[])
{
    // int mass[count];
    int mass[9]={0};
    for (int i = 0; i < count; i++)
    {
        mass[counter(i)]++;
    }
    printf("\n");

    for (size_t i = 0; i < 9; i++)
    {
        printf("%d - %d\n", i,mass[i]);
    }
    return 0;
}