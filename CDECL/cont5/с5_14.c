#include <stdio.h>
#include <string.h>
#include <math.h>

//made by: CDECL
int isprime(int a) {
  int flag = 1;
  for (int i = 2; i < sqrt(a) + 1; i++) {
    if (a % i == 0) {
      flag = 0;
      break;
    }
  }
  return flag;
}

void checker(int N, int i, long int Digit) {
  int other_digit[4] = {1, 3, 7, 9};
  long int cur = Digit * 10;
  if (i == N) {
    printf("%ld ", Digit);
  } 
  else {
    for (int j = 0; j < 4; j++) {
      if (isprime(cur + other_digit[j])) {
        checker(N, i + 1, cur + other_digit[j]);
      }
    }
  }
}

int main(void) {
  int N;
  scanf("%d", &N);
  int first_digit[4] = {2, 3, 5, 7};
  for (long int i = 0; i < 4; i++) {
    checker(N, 1, first_digit[i]);
  }
  return 0;
}
