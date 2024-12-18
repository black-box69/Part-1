#include <stdio.h>

//made by: 2cache

int main(void) {
    unsigned n = 0;
    scanf("%d", &n);

    int k = 0;
    while (n) {
        if (n % 2) k++;
        n/=2;
    }
    printf("%d", k);

    return 0;
}
