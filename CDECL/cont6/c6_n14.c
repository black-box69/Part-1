#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

//made by: CDECL

int main(void) {
    FILE *in = fopen("matrix.in", "rb");
    FILE *out = fopen("trace.out", "wb");
    int N;
    unsigned char cur[2], big[4];
    fread(cur, 2, 1, in);
    N = (cur[0] << 8) + cur[1];
    long long trail = 0, tmp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fread(big, 4, 1, in);
            tmp = (big[0] << 24) + (big[1] << 16) + (big[2] << 8) + big[3];
            if (i == j) trail += tmp;
        }
    }
    for (int i = 0; i < 8; i++) {
        unsigned char check = trail >> (8 * (8 - i - 1));
        fwrite(&check, sizeof(unsigned char), 1, out);
    }
    return 0;
}
