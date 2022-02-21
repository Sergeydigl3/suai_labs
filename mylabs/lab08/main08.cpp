#include <iostream>
#include <math.h>
#include "lab08.h"
using namespace std;

int main(int argc, char *argv[])
{
    double a = 0.5;
    double b = 0.8;
    double eps = 0.00000015;
    double y, dy, In;
    // cin >> a >> b >> eps;
    int n = 1;
    while (1)
    {   
        double f1 = smth_do(a, b, n);
        double f2 = smth_do(a, b, n*2);
        
        printf("Pogreshnost' %lf\n", fabs(f2-f1));
        if (fabs(f2-f1)<=eps){
            cout << "Otvet:" << f1 << endl;
            break;
        }
        n+=1;
    }
}