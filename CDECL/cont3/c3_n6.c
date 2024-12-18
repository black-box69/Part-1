#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//made by: CDECL
int K(int i) {
    if (i <= 3)
        return i;
    else if (i % 2 == 1)
        return (2 * K(i + 3));
    else
        return (3 + K(i / 2));
}

int main(void) {
    int n;
    scanf("%d", &n);
    int res = K(n);
    printf("%d", res);
    return 0;
}
