#include <stdio.h>
#include <stdlib.h>

//made by: CDECL
int main(void) {
    int x, y;
    scanf("%d%d", &x, &y);
    int dif = abs(abs(x) - abs(y));
    int m;
    if (abs(x) <= abs(y))
        m = abs(x);
    else
        m = abs(y);
    int result = m * 2 + dif * 2 - dif % 2;
    printf("%d", result);
    return 0;
}
