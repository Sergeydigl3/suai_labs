// #include <iostream>
// #include <math.h>
// using namespace std;

// double f(double x)
// {
// 	return sin(x*x+2*x);
// }

// int main() {
// 	double a, b, eps;//Нижний и верхний пределы интегрирования (a, b), погрешность (eps).
// 	cin >> a >> b >> eps;
// 	double I=eps+1, I1=0;//I-предыдущее вычисленное значение интеграла, I1-новое, с большим N.
// 	for (int N=2; (N<=4)||(fabs(I1-I)>eps); N*=2)
// 	{
// 		double h, sum2=0, sum4=0, sum=0;
// 		h=(b-a)/(2*N);//Шаг интегрирования.
// 		for (int i=1; i<=2*N-1; i+=2)
// 		{
// 			sum4+=f(a+h*i);//Значения с нечётными индексами, которые нужно умножить на 4.
// 			sum2+=f(a+h*(i+1));//Значения с чётными индексами, которые нужно умножить на 2.
// 		}
// 		sum=f(a)+4*sum4+2*sum2-f(b);//Отнимаем значение f(b) так как ранее прибавили его дважды.
// 		I=I1;
// 		I1=(h/3)*sum;
// 	}
// 	cout << I1 << endl;
// 	return 0;
// }

#include <iostream>
#include <math.h>
using namespace std;

double f(double x) { return (cos(x)); }
double I(double a, double b, int n, double y) { return ((b - a) / (2 * n) * y); }

double smth_do(double a, double b, double n)
{
    double y, dy, In;
    dy = (b - a) / n;
    y = f(a) + f(b);
    for (int i = 1; i < n; i++)
    {
        y += 2 * (f(a + dy * i));
    }
    In = I(a, b, n, y);
    return In;
}

int main()
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