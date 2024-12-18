#include <stdio.h>

//made by: 2cache

int main(void) {
    unsigned n = 0;
    int k = 0;
    scanf("%u %d", &n, &k);

    unsigned pattern = 1;
    for (int i = 0; i < k; i++) {
        pattern <<= 1;
        pattern |= 1;
    }

    pattern &= n;
    n>>=k;
    pattern<<=(32 - k);

    printf("%u", n | pattern);



    return 0;
}
