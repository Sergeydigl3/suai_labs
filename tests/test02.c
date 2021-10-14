#include <stdio.h>

int is_char(int ch)
{
    if (
        (65 <= ch && ch <= 90) || (97 <= ch && ch <= 122) ||
        (128 <= ch && ch <= 175) || (224 <= ch && ch <= 239))
        return 1;
    else
        return 0;
}

int main() {

    char str[100] = { 0 };
    fgets(str, 100, stdin);

    int max1 = -1;
    int max2 = -1;

    int min1 = -1;
    int min2 = -1;

    int tmp1 = -1;
    int tmp2 = -1;

    for (int i = 0; i < 101; i++) {

        if (is_char(str[i]) == 1) {

            if (tmp1 == -1) tmp1 = i;
            if (i == 100) tmp2 = i;
        }
        else {

            if ((tmp2 == -1) && (tmp1 != -1)) tmp2 = i - 1;
        }
        if ((tmp1 != -1) && (tmp2 != -1)) {
            if ((tmp1 - tmp2 + 1) > (max2-max1+1) || max1==-1) {
                max1 = tmp1;
                max2 = tmp2;
            }

            else if ((tmp1 - tmp2 + 1) < (min2-min1+1) || min1==-1) {
                min1 = tmp1;
                min2 = tmp2;
            }
            tmp1=-1;
            tmp2=-1;
        }
    }
    printf("\n");
    for (int i = 0; i < (max2-max1+1); i++) {
        for (int j = min1; j <= min2; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < (min2-min1+1); i++) {
        for (int j = max1; j <= max2; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }

    return 0;
}