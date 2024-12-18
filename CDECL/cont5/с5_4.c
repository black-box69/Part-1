#include <stdio.h>
#include <stdlib.h>

//made by: CDECL
int main(void) {
  int *p = (int *)malloc(sizeof(int));
  int i = 0, cur = 0, comp = 0, ans = 0;
  scanf("%d", &cur);
  while (cur != 0) {
    *(p + i) = cur;
    p = (int *)realloc(p, sizeof(int) * (i + 2));
    comp = cur;
    i++;
    scanf("%d", &cur);
  }
  for (int k = 0; k < i; k++) {
    if (*(p + k) < comp)
        ans++;
  }
  printf("%d", ans);
  free(p);
  return 0;
}
