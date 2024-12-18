#include <stdio.h>

//made by: 2cache

int main(void) {
    int n = 0;
    int k = 0;
    int ammount = 0;
    int a[4000] = {0};
    scanf("%d", &n);
    for (int p = 0; p < n; p++) {
        scanf("%d", &a[p]);
    }
    for (int i = 0; i < n-2; i++) {
        for (int j = i + 2; j < n; j+=2) {
            k = (i + j)/2;
            if (a[k] == (a[i] + a[j])/2 && ((a[i] + a[j]) % 2 == 0)) {
                ammount += 1;
            }
        }
    }

    printf("%d", ammount);
    return 0;
}
