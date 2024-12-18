#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define A -100
#define B 100

//made by: 2cache

int main()
{
  int array[N][N], flag = 0, c = 0, max;
  printf("Iznachalniy massiv:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      array[i][j] = A + rand() % (B - A + 1);
      printf("%4d", array[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (array[i][j] < 0 && array[i][j] % 4 == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      c++;
    }
    flag = 0;
  }
  printf("c=%d \n", c);

  int arr[c];

  for (int i = 0, c = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (array[i][j] < 0 && array[i][j] % 4 == 0 && (array[i][j] > max || flag == 0)) {
        flag = 1;
        max = array[i][j];
      }
    }
    if (flag == 1) {
      arr[c] = max;
      printf("arr[c]=%4d", arr[c]);
      c++;
    }
    flag = 0;
  }

  //////////
  //n rows
  //m cols
  int sums[m] = {0}; // error, fix this
  for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) { // all rows for column j
            if(arr[i][j] % 2 == 0) sum[j] += arr[i][j];
      }
  }
  //////////



     return EXIT_SUCCESS;
}
