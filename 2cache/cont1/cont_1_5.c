#include <stdio.h>

//made by: 2cache

// 1+2*3+4*5+6
int main(void) {
    int a = 0;
    int b = 0;
    int res = 0;
    scanf("%d", &res);

    while (1) {
        scanf("%d", &a);
        if (!a) {
            printf("%d", res);
            return 0;
        }
        scanf("%d", &b);
        if (!b) {
            printf("%d", res + a);
            return 0;
        }
        res += a * b;
    }



    return 0;
}
