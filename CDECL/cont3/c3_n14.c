#include <stdio.h>
#include <string.h>
#include <math.h>

//made by: CDECL
int position(char a) {
  if (a == 'A') return 1;
  if (a == 'B') return 2;
  if (a == 'C') return 3;
  if (a == 'D') return 4;
  if (a == 'E') return 5;
  if (a == 'F') return 6;
  if (a == 'G') return 7;
  if (a == 'H') return 8;
  return 0;
}

int module(int a) {return (a >= 0) ? a : a * -1;}

int queen_move_check(int k_x, int k_y, int q_x, int q_y) {
  return ((module(k_x - q_x) == 1 && module(k_y - q_y) == 2) || (module(k_x - q_x) == 2 && module(k_y - q_y) == 1));
}

int knight_move_check(int k_x, int k_y, int q_x, int q_y) {
  return (((module(k_x - q_x) == module(k_y - q_y)) || k_x == q_x || k_y == q_y) && (k_x != q_x || k_y != q_y));
}
int main(void) {
  int cheat = 0, Garik = 1, q_x = 0, q_y = 0, k_x = 1, k_y = 1, finished = 0, x, y;
  char cur;
  scanf("%c", &cur);
  while (cur != 'X') {
    scanf("%d", &y);
    x = position(cur);
    if (finished || cheat) {
      // printf("%c %d %d %d %d %d %d %d %d ", cur, x, y, finished, cheat, k_x, k_y, q_x, q_y);
      cheat = 1;
      break;
    }
    if (Garik) {
      if (!queen_move_check(k_x, k_y, x, y)) cheat = 1;
      q_x = x;
      q_y = y;
    }
    else {
      if (!knight_move_check(x, y, q_x, q_y)) cheat = 1;
      k_x = x;
      k_y = y;
    }
    if ((k_x == 8 && k_y == 8) || (q_x == 8 && q_y == 8)) finished = 1;
    Garik = 1 - Garik;
    scanf("%c", &cur);
    while (cur == ' ' || cur == '\n') scanf("%c", &cur);
  }
  if (cheat || !finished) printf("Cheaters");
  else {
    if (Garik) printf("Tolik");
    else printf("Garik");
  }
  return 0;
}
