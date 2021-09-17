#include <stdio.h>
int main()
{
    int x, y, otvet;
    printf("Vvedite 2 chisla\n");
    scanf_s("%d %d", &x, &y);
    otvet = x - y;
    printf("Raznost vtorogo i tretego chisla: %d - %d = %d\n", x, y, otvet);
    return 0;
}

