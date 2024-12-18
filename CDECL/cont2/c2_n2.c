#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//made by: CDECL
int main(void) {
    int ndigit[10000], h, i=0;
    scanf("%d", &h);
    while (h != 0) {
        ndigit[i] = h;
        scanf("%d", &h);
        i += 1;
    }
    for (int j = 0; j < i; j += 2) {
        printf("%d ", ndigit[j]);
    }
    for (int j = i - 1 - (i % 2); j > 0; j -= 2) {
        printf("%d ", ndigit[j]);
    }
    return 0;
}
