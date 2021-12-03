#include <stdio.h>

int main(int argc, char *argv[])
{
    int N = 5;
     
    int (*words)[2] = (int (*)[2])malloc( N * 2 * sizeof( int ) );
    for (size_t i = 0; i < N; i++)
    {
        words[i][0]=-1;
        words[i][1]=-1;
    }
    for (size_t i = 0; i < N; i++)
    {
        printf("%d %d\n", words[i][0],words[i][1]);
    }
    
    return 0;
}