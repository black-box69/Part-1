#include <stdio.h>
#include <string.h>

//made by: CDECL

int main(void)
{
  int N;
  scanf("%d\n", &N);
  char a[1000002];
  fgets(a, 1000002, stdin);
  int len = strlen(a) - 1, spaces = 0;
  for (int i = 0; i < len; i++) {
    if (a[i] == ' ') {
      spaces++;
    }
  }
  int h[spaces];
  for (int i = 0; i < spaces; i++) {
    h[i] = 1;
  }
  int add = N - len, i = 0;
  while (add > 0) {
    h[i]++;
    i = (i + 1) % spaces;
    add--;
  }
  int k = 0;
  for (int i = 0; i < len; i++) {
    if (a[i] == ' ') {
      for (int j = 0; j < h[k]; j++) {
        printf(" ");
      }
      k++;
    }
    else {
      printf("%c", a[i]);
    } 
  }
  return 0;
}
