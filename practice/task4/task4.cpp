#include "stdio.h"

int main() {
    int k;
    scanf("%d", &k);

    unsigned long long p1[k + 1] = { 0 };
    unsigned long long p2[k + 1] = { 0 };
    p2[0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int x = 0; x <= k; x++)
            p1[x] = p2[x];
        for (int x = 1; x <= k; x++)
            p2[x] = p1[x - 1] + p1[x];
    }

    for (int i = 0; i <= k; i++)
        printf("%llu ", p2[i]);
    printf("\n");
}