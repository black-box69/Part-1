#include <stdio.h>
#include <limits.h>

//made by: 2cache

int main(void) {
    unsigned n = 0;
    int k = 0, max = INT_MIN, buf = 0;
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i = 0; i < 32 - k + 1; i++) {
        buf = (n << i) >> (32 - k);
        if (buf > max) {
            max = buf;
        }
    }
    printf("%d ", max);
    return 0;
}
