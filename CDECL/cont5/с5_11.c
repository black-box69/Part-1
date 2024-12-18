#include <stdio.h>
#include <string.h>


//made by: CDECL
unsigned max(unsigned a, unsigned b, unsigned c) {
  if (a >= b && a >= c)
    return a;
  else if (b >= a && b >= c)
    return b;
  else
    return c;
}

int main(void)
{
  int N, M;
  scanf("%d%d", &N, &M);
  N += 2;
  unsigned arr[N][M], cur;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (i == 0 || i == N - 1)
        arr[i][j] = 0;
      else {
        scanf("%u", &cur);
        arr[i][j] = cur;
      }
    }
  }
  for (int j = 1; j < M; j++) {
    for (int i = 1; i < N - 1; i++) {
      arr[i][j] += max(arr[i - 1][j - 1], arr[i][j - 1], arr[i + 1][j - 1]);
    }
  }
  unsigned ans = 0;
  for (int i = 1; i < N - 1; i++) {
    ans = max(ans, arr[i][M - 1], 0);
  }
  printf("%u", ans);
  return 0;
}
