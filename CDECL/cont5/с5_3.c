#include <stdio.h>
#include <stdlib.h>

//made by: CDECL

int main(void) {
  int *p_odd = (int *) malloc(sizeof(int));
  int *p_even = (int *) malloc(sizeof(int));
  int i = 0, j = 0, k = 0, cur;
  scanf("%d", &cur);

  while (cur != 0) {
    if (i % 2 == 0) {
      *(p_odd + j) = cur;
      p_odd = (int *) realloc(p_odd, sizeof(int) * (j + 2));
      j++;
    }
    else {
      *(p_even + k) = cur;
      p_even = (int *) realloc(p_even, sizeof(int) * (k + 2));
      k++;
    }
    i++;
    scanf("%d", &cur);
  }

  for (int m = 0; m < j; m++) {
    printf("%d ", *(p_odd + m));
  }
  for (int m = 0; m < k; m++) {
    printf("%d ", *(p_even + m));
  }

  free(p_even);
  free(p_odd);
  return 0;
}
