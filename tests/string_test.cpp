#include <iostream>
#include <string.h>
using namespace std;

int main()
{   
    char str [] = "This , a sample string . " ;
    char * pch = strtok ( str , " ," );
    while ( pch != NULL ) {
        printf ( " %s \n " , pch );
        pch = strtok ( NULL , " ,. - " );
    }
    printf("\n\n%s\n", str);
    return 0;
}