#include <stdio.h>

//made by: 2cache

int main(void) {
    int N = 0, buf = 0, in = 0;
    scanf("%d", &N);
    scanf("%d", &buf);
    for (int i = 0; i < N-1; i++) {
        scanf("%d", &in);
        buf = buf ^ in;
    }
    printf("%d", buf);
    return 0;
}
