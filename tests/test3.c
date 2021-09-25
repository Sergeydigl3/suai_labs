#include <stdio.h>


int main(int argc, char const *argv[])
{
    int st1[100]={0};
    int st2[100]={0};
    if (st1==st2)
        printf("PIZDA");
    else
        printf("test");
    return 0;
}

int similar(char *st1, char *st2, int size){
    for (int x=0; x<size;x++)
        if (st1[x]!=st2[x])
            return 0;
    return 1;
}