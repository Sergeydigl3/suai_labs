#include <stdio.h>

void tfunc(char *xd){
    xd++;
    printf("%c", *xd);
}

int main (int argc, char *argv[]) {
    char mass[] = "TEST";
    tfunc(mass);

   return 0;
}