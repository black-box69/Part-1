#include <stdio.h>

//made by: 2cache

int main(void) {
    //0 3 6
    //2 2 7
    int arr[2][3] = {{0, 3, 6}, {2, 2, 7}};
    int n = 2, m = 3;
    int sums[3] = {0}; // error, fix this
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) { // all rows for column j
            if(arr[i][j] % 2 == 0) sums[j] += arr[i][j];
      }
    }

    for (int i = 0; i < m; i++) {
        printf("%d", sums[i]);
    }
    return 0;
}
