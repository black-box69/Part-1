#include <stdio.h>
#include <string.h>

//made by: CDECL

int main(void)
{
  char str[1000002];
  int as[1000002] = {0};
  fgets(str, 1000002, stdin);
  int len = strlen(str) - 1;
  int left_even = 0, left_odd = 0, right_even = 0, right_odd = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == 'A')
      as[i] = 1;
  }
  for (int i = 0; i < len; i++) {
    if (as[i] == 1) {
      if (i % 2 == 0)
        right_even++;
      else
        right_odd++;
    }
  }
  for (int i = 0; i < len; i++) {
    if (as[i] == 1) {
      if (i % 2 == 0)
        right_even--;
      else
        right_odd--;
    }
    if (right_odd + left_odd == right_even + left_even)
      printf("%d ", i+1);
    if (as[i] != 0) {
      if (i % 2 == 0)
        left_odd++;
      else
        left_even++;
    }
  }
  return 0;
}
