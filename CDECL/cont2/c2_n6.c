#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//made by: CDECL
int main(void) {
    int N, h;
    scanf("%d", &N);
    int mov[N], arr[N], arr2[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &h);
        mov[i] = h - 1;
        arr[i] = i + 1;
        arr2[i] = i + 1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j ++) {
            arr[j] = arr2[mov[j]];
        }
        for (int j = 0; j < N; j ++) {
            arr2[j] = arr[j];
        }
    }

    for (int i = 0; i < N; i ++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
