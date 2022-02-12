// Написать функцию для перевода переменной типа long в символьную строку в восьмеричном представлении ( ltoao( long num, char s[]) ) и тестирующую программу к ней.

#include "lab07.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    int number[211] = {0};
    
    for (int n = 1; n <= 10000; n++)
    {
        int x = gen(); 
        printf("%d ", x);
        number[x]++;
    }
    int sum = 0;
    for (size_t i = 0; i < 211; i++)
    {
        sum+=number[i];
    }
    

    return 0;
}