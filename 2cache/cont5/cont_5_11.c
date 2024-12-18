#include <stdio.h>
#include <stdlib.h>
#define MAX(X, Y) ((X) > (Y)) ? (X) : (Y)

//made by: 2cache

int main(void) {
    unsigned n = 0, m = 0;
    scanf("%u", &n);
    scanf("%u", &m);
    unsigned **table = malloc((n + 2) * sizeof(unsigned*));

    for (int i = 0; i < n + 2; i++) {
        table[i] = malloc(m * sizeof(unsigned));
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n + 1) table[i][j] = 0;
            else scanf("%u", &table[i][j]);
        }
    }

    for (int col = 1; col < m; col++) {
        for (int row = 1; row < n + 1; row++) {
            //printf("%u %u %u now: %u", table[row][col - 1], table[row + 1][col - 1], table[row - 1][col - 1], table[row][col]);
            table[row][col] += MAX(MAX(table[row][col - 1], table[row + 1][col - 1]), table[row - 1][col - 1]);
        }
    }

    unsigned max = 0;

    for (int i = 1; i < n + 1; i++) {
        max = (max < table[i][m - 1]) ? table[i][m - 1] : max;
    }


    printf("%u", max);
    //int col = 0;
    //while (col != m) {

    //}

    return 0;
}
