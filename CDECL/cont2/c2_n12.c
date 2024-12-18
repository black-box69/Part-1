#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//made by: CDECL
int main(void) {
    int front[8], side[8], s = 0, mf = 0, ms = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &front[i]);
    }
    for (int i = 0; i < 8; i++) {
        scanf("%d", &side[i]);
    }

    for (int i = 0; i < 8; i++) {
        if (front[i] >= mf)
            mf = front[i];
        if (side[i] >= ms)
            ms = side[i];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (front[i] >= side[j]) {
                s += side[j];
            }
            else {
                s += front[i];
            }
        }
    }

    if (mf != ms)
        printf("-1");
    else
        printf("%d", s);
    return 0;
}
