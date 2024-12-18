#include <stdio.h>

//made by: 2cache

int main(void) {
    int N = 0, s = 0;
    scanf("%d", &N);

    int arr1[10000] = {0}, arr2[10000] = {0};

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr2[i]);
        s += arr1[i];
        if (arr2[i] > arr1[i]) {
            s += arr2[i] - arr1[i];
        }
    }

    printf("%d", s);

    return 0;
}
