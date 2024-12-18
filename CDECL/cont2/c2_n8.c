#include <stdio.h>
#include <math.h>

//made by: CDECL
int main(void) {
    long int N, c = 0, k = 0;
    scanf("%ld", &N);
    double arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 2; j < N; j += 2) {
            k = (i + j) / 2;
            if (fabs((arr[i] + arr[j]) / 2 - arr[k]) < 0.4) {
                c += 1;
            }
        }
    }
    printf("%ld", c);
    return 0;
}
