#include <stdio.h>

void sort_int(int *mass, int size, int revert)
{
    if (revert == 1)
    {
        for (int j = 0; j < size; j++)
        {
            for (int i = (size - 1); i > j; i--)
            {
                if (mass[i - 1] < mass[i])
                {
                    int temp = mass[i - 1];
                    mass[i - 1] = mass[i];
                    mass[i] = temp;
                }
            }
        }
    }
    else
        for (int j = 0; j < size; j++)
        {
            for (int i = (size - 1); i > j; i--)
            {
                if (mass[i - 1] > mass[i])
                {
                    int temp = mass[i - 1];
                    mass[i - 1] = mass[i];
                    mass[i] = temp;
                }
            }
        }
}

void sort_str(char **mass, int size, int word_size, int revert)
{
    if (revert == 1)
    {
        for (int j = 0; j < size; j++)
        {

            for (int i = (size - 1); i > j; i--)
            {   
                pr_s = 1;
                ns_s =1;
                if (mass[i - 1] < mass[i])
                {
                    int temp = mass[i - 1];
                    mass[i - 1] = mass[i];
                    mass[i] = temp;
                }
            }
        }
    }
    else
        for (int j = 0; j < size; j++)
        {
            for (int i = (size - 1); i > j; i--)
            {
                if (mass[i - 1] > mass[i])
                {
                    int temp = mass[i - 1];
                    mass[i - 1] = mass[i];
                    mass[i] = temp;
                }
            }
        }
}

int main(int argc, char const *argv[])
{
    int tmas[] = {32, 1, 8, 3};
    // printf("Before %d\n", tmas[0]);
    print_array(tmas, 4);
    sort_int(tmas, 4, 1);
    printf("\nFormat\n");
    print_array(tmas, 4);
    return 0;
}

int print_array(int x[], int len)
{
    int k;

    for (k = 0; k < len; k++)
    {
        printf("x[%d] = %d\n", k, x[k]);
    }
    return 0;
}
