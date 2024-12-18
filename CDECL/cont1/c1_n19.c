#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//made by: CDECL

int main(void) {
    unsigned a11[32], a12[32], a21[32], a22[32], b1[32], b2[32];
    unsigned long c1, c2, c3, c4, c5, c6, ans1 = 0, ans2 = 0, p = 1;
    scanf("%lu%lu%lu%lu%lu%lu", &c1, &c2, &c3, &c4, &c5, &c6);

    for (int i = 0; i < 32; i++) {
        a11[i] = c1 % 2;
        c1 /= 2;
    }
    for (int i = 0; i < 32; i++) {
        a12[i] = c2 % 2;
        c2 /= 2;
    }
    for (int i = 0; i < 32; i++) {
        a21[i] = c3 % 2;
        c3 /= 2;
    }
    for (int i = 0; i < 32; i++) {
        a22[i] = c4 % 2;
        c4 /= 2;
    }
    for (int i = 0; i < 32; i++) {
        b1[i] = c5 % 2;
        c5 /= 2;
    }
    for (int i = 0; i < 32; i++) {
        b2[i] = c6 % 2;
        c6 /= 2;
    }

    unsigned x[32], y[32];
    int h = 0, broke = 0;
    for (int i = 0; i < 32; i++) {
        h = 0;
        for (int j = 1; j >= 0; j--) {
            for (int k = 1; k >= 0; k--) {
                if ((((a11[i] & j) ^ (a12[i] & k)) == b1[i]) && (((a21[i] & j) ^ (a22[i] & k)) == b2[i])) {
                    x[i] = j;
                    y[i] = k;
                }
                else {
                    h += 1;
                }
            }
        }
        if (h == 4) {
            broke += 1;
        }
    }
    if (broke > 0) {
        printf("No");
    }
    else {
        for (int i = 0; i < 32; i++) {
            ans1 += p * x[i];
            ans2 += p * y[i];
            p *= 2;
        }
        printf("Yes\n");
        printf("%lu %lu", ans1, ans2);
    }
    return 0;
}
