#include <stdio.h>

//made by: 2cache

int main(void) {
    int arr[10000] = {0};
    int m = 0, i = 0;
    scanf("%d", &m);

    while (m != 0) {
        arr[i] = m;
        i++;
        scanf("%d", &m);
    }

    for (i = i - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    return 0;
}
