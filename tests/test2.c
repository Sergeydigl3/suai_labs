#include <stdio.h>


int main(int argc, char const *argv[])
{
    int data, step;
    scanf_s("%d %d", &data, &step);
    printf("%d", pow(data, step));

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