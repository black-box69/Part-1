#include <stdio.h>
#include <string.h>

//made by: CDECL

int min(int a, int b) {
  if (a < b) return a;
  return b;
}

int main(void)
{
    char a[1000000], b[1000000];
    scanf("%s", a);
    scanf("%s", b);
    int len_1 = strlen(a), len_2 = strlen(b), mov1 = 0, mov2 = 0, len = min(len_1, len_2);
    if (len_1 == 0 || len_2 == 0) {
      printf("0 0");
      return 0;
    }
    if (len_1 > len_2)
      mov1 = len_1 - len_2;
    else
      mov2 = len_2 - len_1;
    int lps1[len], lps2[len], pointer = 0;
    int flag = 0;
   for (int i = 0; i < len; i++) {
      if (a[i + mov1] == b[pointer]) {
        if (flag == 1) {
          lps1[i] = lps1[i - 1];
          pointer = lps1[i];
        }
        else 
          lps1[i] = ++pointer;
        flag = 0;
      }
      else {
        if (pointer != 0) {
          flag = 1;
          pointer--;
          i--;
        }
        else {
          lps1[i] = 0;
          pointer = 0;
          flag = 0;
        }
      }
    }
    pointer = 0;
    flag = 0;
    for (int i = 0; i < len; i++) {
      if (b[i + mov2] == a[pointer]) {
        if (flag == 1) {
          lps2[i] = lps2[i - 1];
          pointer = lps2[i];
        }
        else 
          lps2[i] = ++pointer;
        flag = 0;
      }
      else {
        if (pointer != 0) {
          flag = 1;
          pointer--;
          i--;
        }
        else {
          lps2[i] = 0;
          pointer = 0;
          flag = 0;
        }
      }
    }
    printf("%d %d", lps2[len - 1], lps1[len - 1]);
    return 0;
}
