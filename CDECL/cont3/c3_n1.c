#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//made by: CDECL
int nod(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return (a + b);
}

int main(void) {
    int a, b, c, d, ans;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ans = nod(nod(a, b), nod(c, d));
    printf("%d", ans);
    return 0;
}
