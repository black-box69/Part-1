#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

//made by: CDECL
int min(int x, int y) {
  return (x > y) ? y : x;
}

int max(int x, int y) {
  return (x > y) ? x : y;
} 

int main(void) {
  int N, M, k;
  scanf("%d%d%d", &N, &M, &k);
  int viruses[k][2], x, y;
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &y, &x);
    viruses[i][0] = x;
    viruses[i][1] = y;
  }
  int ans = 0, m = INT_MAX;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      m = INT_MAX;
      for (int s = 0; s < k; s++) {
        m = min(m, abs(viruses[s][0] - i) + abs(viruses[s][1] - j));
      }
      ans = max(m, ans);
    }
  }
  printf("%d", ans);
  return 0; 
}
