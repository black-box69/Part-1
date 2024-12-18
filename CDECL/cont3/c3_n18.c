#include <stdio.h>
#include <math.h>

//made by: CDECL
long int connect(long int x) {
    int c = 10;
    while (x >= c)
        c *= 10;
    return x * c + x;
}


int main(void) {
    long int A, N;
    scanf("%ld%ld", &N, &A);
    int checker[2010];
    for (int i = 0; i < 2010; i++) {
        checker[i] = 0;
    }
    int el = N % 2010;
    while (checker[el] == 0) {
        if (el == A) {
            printf("YES");
            return 0;
        }
        checker[el] = 1;
        el = connect(el) % 2010;
    }
    printf("NO");
    return 0;
}
