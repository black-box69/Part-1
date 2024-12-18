#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//made by: CDECL
int main(void) {
    long int n, a, maximum, prev_max, minimum, prev_min;
    scanf("%ld", &n);
    scanf("%ld", &a);
    maximum = minimum = a;
    prev_max = LONG_MIN;
    prev_min = LONG_MAX;
    for (int i = 1; i < n; i++) {
        scanf("%ld", &a);
        if (a >= maximum) {
            prev_max = maximum;
            maximum = a;
        }
        else if (a > prev_max) {
            prev_max = a;
        }
        if (a <= minimum) {
            prev_min = minimum;
            minimum = a;
        }
        else if (a < prev_min) {
            prev_min = a;
        }
    }
    if (maximum * prev_max > minimum * prev_min) {
        printf("%ld %ld", prev_max, maximum);
    }
    else {
        printf("%ld %ld", minimum, prev_min);
    }
    return 0;
}
