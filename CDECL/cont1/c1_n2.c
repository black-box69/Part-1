#include <stdio.h>
#include <stdlib.h>

//made by: CDECL
int main(void) {
    int N, maximum = -2147483648, h, counter = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &h);
        if (h == maximum) {
            counter++;
        }
        else if (h > maximum) {
            maximum = h;
            counter = 1;
        }
    }
    printf("%d", counter);
    return 0;
}
