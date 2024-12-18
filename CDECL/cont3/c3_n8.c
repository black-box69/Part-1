#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//made by: CDECL
int med(long int a, long int b, long int c) {
    long int h;
    // выбираю среднее по величине число
    if (c > b) {
        h = c;
        c = b;
        b = h;
    }
    if (b > a) {
        h = a;
        a = b;
        b = h;
    }
    if (c > b) {
        h = c;
        c = b;
        b = h;
    }
    return b;
}

int main(void) {
    long int N, centr, h, prev;
    scanf("%ld", &N);
    long int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &arr[i]);
    }
    centr = N / 2;
    for (int i = 0; i <= centr; i++) {
        h = arr[i];
        for (int j = i + 1; j < N - i - 1; j++) {
            prev = arr[j];
            arr[j] = med(h, arr[j], arr[j + 1]);
            h = prev;
        }
    }
    printf("%ld", arr[centr]);
    return 0;
}
