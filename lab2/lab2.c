#include <stdio.h>


// int main(int argc, char const *argv[])
// {
//     char str[100];
//     fgets(str, 10, stdin);
//     fflush(stdin);
    
//     // printf("%d", );
//     return 0;
// }

int main(int argc, char const *argv[])
{
    for (int x=0;x<=300;x++){
        printf("%c %d %d\n", x,x, is_char(x));
    }
    return 0;
}



int is_char(int ch){
    printf("%d", ch);
    if ( 
        (65<=ch&&ch<=90) || (97<=ch&&ch<=122)
        ||
        (128<=ch&&ch<=175) || (224<=ch&&ch<=239)
    )
        return 1;
    else
        return 0;

}