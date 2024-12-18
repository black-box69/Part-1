#include <stdio.h>
#include <math.h>

//made by: CDECL
int power(int a, int b) {
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  int x = power(a, b / 2);
  x = x * x;
  if (b % 2 == 1)
    x = x * a;
  return x;
}

int power_m(int n, int p, int m) {
  if (p == 0) 
    return 1;
  else if (p == 1 || n == 1 || n == 0) 
    return n % m;
  int x = power_m(n, p / 2, m) % m;
  x = x * x % m;
  if (p % 2 == 1) 
    x = x * n % m;
  return x % m;
}

int max_3(int a, int b, int c) {
  if (a >= b && a >= c) return a;
  if (b >= a && b >= c) return b;
  else return c;
}

int max_2(int a, int b) {
  return (a > b) ? a : b;
}

int main(void) {
    int a, b, c, m;
    scanf("%d%d%d%d", &a, &b, &c, &m);
    int a_b = power(a, b), a_c = power(a, c), b_a = power(b, a);
    int b_c = power(b, c), c_a = power(c, a), c_b = power(c, b);
    
    int a_b_c = power_m(a, b_c, m);
    int a_c_b = power_m(a, c_b, m);
    int b_a_c = power_m(b, a_c, m);
    int b_c_a = power_m(b, c_a, m);
    int c_a_b = power_m(c, a_b, m);
    int c_b_a = power_m(c, b_a, m);
    
    printf("%d", max_3(max_2(a_b_c, a_c_b), max_2(b_c_a, b_a_c), max_2(c_b_a, c_a_b)));
}
