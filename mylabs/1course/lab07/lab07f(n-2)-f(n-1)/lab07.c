#include <stdio.h>

int gen () {
    static int f1 = 1; static int f2 = 1; static int f3;
    f3 = ( f2 + f1 ) % 211;
    f1 = f2 ;
    f2 = f3 ;
    return f3 ;
}

