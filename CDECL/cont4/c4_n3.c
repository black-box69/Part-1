#include <stdio.h>
#include <string.h>

//made by: CDECL

int main(void)
{
  char a[10000];
  scanf("%s", a);
  int len = strlen(a);
  int errors = 0;
  for (int t = 1; t <= len; t++) {
      for (int i = t; i < len; i++) {
        if (a[i] != a[i - t]) {
          errors++;
        } 
      }
      if (errors == 0) {
        printf("%d ", t);
      }
      errors = 0;
  }
  return 0;
}
