// int get_odd_array (int* src , int n , int * dst ) {
//     int count = 0;
//     for (int i = 0; i < n ; i ++)
//         if( src [ i ] % 2 == 1) count ++;
//     dst = malloc ( count * sizeof (int) ); count = 0;
//     for (int i = 0; i < n ; i ++)
//         if( src [ i ] % 2 == 1) dst [ count ++] = src [ i ];
//         return count ;
// }
// int main () {
// int * result = NULL;
// int size = get_odd_array ( array , 42 , result );
// result [0] = 42;
// free ( result );
// }   

int get_chislo(){
    int a = 5;
    return a;
}

int main(int argc, char const *argv[])
{
    int ch = get_chislo();
    return 0;
}
