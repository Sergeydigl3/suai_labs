#include "lab07.h"
#include <stdio.h>


// TODO: strtod String to Double
int main(int argc, char *argv[])
{
    while (1)
    {   
        char p[30] = {0};
        long a;
        scanf("%ld", &a);
        ltoao(a, p);
        printf("%s", p);
        // printf(" %o\n", a);
    }
}