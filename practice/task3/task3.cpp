#include <stdio.h>


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
int main()
{
    int mass[5] = {0};
    
    for (int i = 0; i < 16; i++)
    {
        mass[counter2(i)]++;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Kol-vo once %d - %d\n", i ,mass[i]);
    }
    printf("\n");
    return 0;
}