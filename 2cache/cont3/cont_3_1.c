#include <stdio.h>
#define ABS(X)  (X) < 0 ? ((-X)) : (X)
#define MIN(X, Y) (X) < (Y) ? (X) : (Y)

//made by: 2cache

int nod(int a, int b) { // binary GCD algorithm (Wikipedia)
    if ((a == 0) && (b != 0)) return b;
    if ((a != 0) && (b == 0)) return a;
    if ((a%2 == 0) && (b%2 == 0)) return 2 * nod(a / 2, b / 2);
    if ((a % 2 != 0) && (b % 2 == 0)) return nod(a, b / 2);
    if ((b % 2 != 0) && (a % 2 == 0)) return nod(a / 2, b);
    if ((a % 2 != 0) && (b % 2 != 0)) return nod(ABS((a-b)), MIN(a, b));
    return 1;
}

int main(void) {
    int x = 0, y = 0, z = 0, w = 0;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    scanf("%d", &w);
    printf("%d", nod(nod(z, w), nod(x, y)));

    return 0;
}
