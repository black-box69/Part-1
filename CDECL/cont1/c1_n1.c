#include <stdio.h>
#include <stdlib.h>

//made by: CDECL
int main(void)
{
    int N;
    scanf("%d", &N);
    int ndigit[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &ndigit[i]);
    }
    int maximum = 0, minimum = 100000000;
    for (int i = 0; i < N; i++) {
        if (ndigit[i] > maximum) {
            maximum = ndigit[i];
        }
        if (ndigit[i] < minimum) {
            minimum = ndigit[i];
        }
    }
    printf("%d\n", maximum - minimum);
    return 0;
}
