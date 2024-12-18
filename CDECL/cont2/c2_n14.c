#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//made by: CDECL
int main(void) {
    int N;
    scanf("%d", &N);
    int arr[N], h[N], ans[N], broke = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        h[i] = i + 1;
    }
    int a = 0, c = 0;
    for (int i = 0; i < N; i++) {
        a = 0;
        c = 0;
        while ((a != arr[i] || h[N - 1 - c] == 0) && c < N) {
            if (h[N - 1 - c] != 0) {
                a += 1;
            }
            c += 1;
        }
        if (c >= N) {
            broke += 1;
        }
        else {
            ans[i] = h[N - 1 - c];
            h[N - 1 - c] = 0;
        }
    }

    if (broke == 0) {
        for (int i = 0; i < N; i++) {
            printf("%d ", ans[i]);
        }
    }
    else {
        printf("-1");
    }
    return 0;
}
