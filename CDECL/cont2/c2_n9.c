#include <stdio.h>
#include <math.h>

//made by: CDECL
int main(void) {
    long int N, M;
    scanf("%ld", &N);
    long int coef[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &coef[i]);
    }
    scanf("%ld", &M);
    long int arg[M];
    for (int i = 0; i < M; i++) {
        scanf("%ld", &arg[i]);
    }

    long int h = 1, ans = 0;
    for (int i = M - 1; i >= 0; i--) {
        h = 1;
        ans = 0;
        for (int j = 0; j < N; j++) {
            ans += h * coef[j];
            h *= arg[i];
        }
        printf("%ld ", ans);
    }

    return 0;
}
