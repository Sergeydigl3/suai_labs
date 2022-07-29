#include <stdio.h>
#include "lab07.h"

// TODO: strtod String to Double
int main(int argc, char *argv[])
{
    while (1)
    {   
        char str[30] = {0};
        scanf("%s", &str);
        printf("%lf\n", str_to_double(str));
    }
}