#include <stdio.h>

//made by: 2cache

int main(void) {
    unsigned a= 0, b=0,c=0,d=0;
    scanf("%u %u %u %u", &a, &b, &c, &d);
    unsigned abcd = 0;
    d <<= 24;
    c <<= 16;
    b <<= 8;
    
    abcd |= d;
    abcd |= c;
    abcd |= b;
    abcd |= a;
    printf("%u", abcd);

    return 0;
}
