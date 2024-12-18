#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//made by: CDECL
int choice(int n, int k, int len, int arr[]) {
    // условие выхода
    if (len == k) {
        for (int i = 0; i < k; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return 0;
    }

    // выбираем минимальный элемент, с которого можно начать на конкретной позиции
    int i;
    if (len == 0)
        i = 0;
    else
        i = arr[len - 1] + 1;
    len++;
    // перебираем все варианты элемента на заданной позиции
    while (i < n) {
        arr[len - 1] = i;
        choice(n, k, len, arr);
        i++;
    }
    len--;
    return 0;
}

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[k], len = 0;
    choice(n, k, len, arr);
    return 0;
}
