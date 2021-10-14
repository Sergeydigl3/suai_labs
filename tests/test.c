#include <stdio.h>


int main(int argc, char const *argv[])
{
        char str[100];
        fgets(str, 10, stdin);
        fflush(stdin);
        
        printf("%d", pow(10,3));
        return 0;
    }



int pow(int x, int y){
    int res=1;
    int counter = 0;
    while (counter<y){
        res = res*x;
        counter++;
    }
    return res;
}