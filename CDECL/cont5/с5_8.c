#include <stdio.h>
#include <string.h>


//made by: CDECL
int min(int a, int b) {
  if (a == -1)
    return b;
  return (a > b) ? b : a;
}

int main(void)
{
  int N, xn, yn, xk, yk;
  scanf("%d%d%d%d%d", &N, &xn, &yn, &xk, &yk);
  int arr[N][N], size = N * N, flag = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      arr[i][j] = -1;
    }
  }
  arr[xn - 1][yn - 1] = 0;
  for (int k = 0; k < size; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (arr[i][j] != -1) {
          if (i - 1 >= 0 && j - 2 >= 0)
            arr[i - 1][j - 2] = min(arr[i - 1][j - 2], arr[i][j] + 1);
          if (i - 2 >= 0 && j - 1 >= 0)
            arr[i - 2][j - 1] = min(arr[i - 2][j - 1], arr[i][j] + 1);
          if (i + 1 < N && j + 2 < N)
            arr[i + 1][j + 2] = min(arr[i + 1][j + 2], arr[i][j] + 1);
          if (i + 2 < N && j + 1 < N)
            arr[i + 2][j + 1] = min(arr[i + 2][j + 1], arr[i][j] + 1);
          if (i + 1 < N && j - 2 >= 0)
            arr[i + 1][j - 2] = min(arr[i + 1][j - 2], arr[i][j] + 1);
          if (i + 2 < N && j - 1 >= 0)
            arr[i + 2][j - 1] = min(arr[i + 2][j - 1], arr[i][j] + 1);
          if (i - 1 >= 0 && j + 2 < N)
            arr[i - 1][j + 2] = min(arr[i - 1][j + 2], arr[i][j] + 1);
          if (i - 2 >= 0 && j + 1 < N)
            arr[i - 2][j + 1] = min(arr[i - 2][j + 1], arr[i][j] + 1);
        }
      }
    }
    if (arr[xk - 1][yk - 1] != -1 && flag == 1) {
      if (size > 20)
        k = size - 20;
      flag = 0;
    }
  }
  printf("%d\n", arr[xk - 1][yk - 1]);
  
  return 0;
}
