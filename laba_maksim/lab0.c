#include <stdio.h>
int main()
{
    int x, y, z, otvet;
    scanf_s("%d %d %d", &x, &y, &z);
    otvet = x - y;
    printf("%d\n", otvet);
    return 0;
}