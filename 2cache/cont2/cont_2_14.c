#include <stdio.h>

//made by: 2cache

int main(void) {
    int n = 0;
    int warning = 0;
    scanf("%d", &n);

    int m[1000] = {0};
    int marker[1000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
        int counter = m[i] + 1; //number from the edge
        for (int j = n - 1; j >= 0; j--) {
            if (!marker[j]) counter--;
            if (!counter) {
                m[i] = j + 1;
                marker[j] = 1;
                break;
            }
        }
        if (counter) {
            warning = 1;
            break;
        }
    }

    if (warning) printf("-1");
    else {
        for (int i = 0; i < n; i++) {
            printf("%d ", m[i]);
        }
    }

    return 0;
}
