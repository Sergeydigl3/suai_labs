#include <stdio.h>

int main(int argc, char const *argv[])
{
    int tmass[] = {1,20, 34, 52};


    return 0;
}

void find_close(int *mass, int x, int size){
    int mindif=-1;
    int pos1=-1;
    int pos2=-1;

    for (int i=0;i<size;i++){
        int diff = abs(x-mass[i]);
        if (mindif==-1 || diff<=mindif){
            if (diff==mindif)
                pos2 = i;
            else
                pos1 = i;
            printf("%d",diff);
            mindif = diff;
        }
    }

}

int abs(int x){
    if (x<0)
        return x*(-1);
    return x;
}