#include <stdio.h>

int main()
{
    int hod=0;
    int maxx = 0;
    int prev = 0;
    while (1)
    {
        int sx, x;
        scanf_s("%d", &sx);

        if (sx == 0)
            break;
        else
        {

            if (hod==1)
            {
                x = prev + sx;
                printf("Prev: %d;Sec: %d; Duo: %d\n", prev, sx, prev+sx);
                if (x > maxx || maxx == 0)
                    maxx = x;

                hod = 0;
            }
            else
            {   
                prev = sx;
                hod = 1;
            }
            
            
        };
    };
    printf("%d", maxx);
    return 0;
}