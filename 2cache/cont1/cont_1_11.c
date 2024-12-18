#include <stdio.h>

//made by: 2cache

int main(void) {
    unsigned n = 0;
    scanf("%u", &n);

    unsigned pat = 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1;
    pat <<= 24;
    n^= pat;
    printf("%u", n);
    
    return 0;
}
