#include <stdio.h>
#include <string.h>

//made by: CDECL

int main(void)
{
  char a[102];
  int digits[1000];
  scanf("%s", a);
  int len = strlen(a), ans = 0, cur = 0;
  for (int i = 0; i < 1000; i++) {
    digits[i] = 0;
  }
  for (int i = 0; i < len - 2; i++) {
    for (int j = i + 1; j < len - 1; j++) {
      for (int k = j + 1; k < len; k++) {
        cur = 100 * (a[i] - 48) + 10 * (a[j] - 48) + (a[k] - 48) ;
        digits[cur] = 1;
      }
    }
  }
  for (int i = 100; i < 1000; i++) {
    ans += digits[i];
  }
  printf("%d", ans);
  return 0;
}
