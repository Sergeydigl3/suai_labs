#include <stdio.h>

int main()
{
    int a, b, res;
    printf("Enter two integers: \n");
    scanf_s("%d %d", &a, &b);
    res = a + b;
    printf("Sum of two elements: %d+%d=%d", a, b, res);  
    return 0;
}


       