#include <stdio.h>
#include <limits.h>
#include <math.h>

//made by: 2cache

int get_num(char first_digit) {
    int num = 0;
    int sign = 1;
    if (first_digit == '-') {
        sign = -1;
        num = sign * (getchar() - '0');
    }

    else {
        sign = 1;
        num = first_digit - '0';
    }

    int new_digit = (getchar() - '0');

    while ((new_digit >= 0) && (new_digit <= 9)) {
        num = num * 10 + sign * new_digit;
        new_digit = getchar() - '0';
    }
    //printf("%d", num);
    return num;
}

int ppn(char op) {
    if (op == ' ') return ppn(getchar());
    if (op == '*') return ppn(getchar()) * ppn(getchar());
    if (op == '/') return ppn(getchar()) / ppn(getchar());
    if (((op - '0' >= 0) && (op - '0' <= 9)) || (op == '-')) return get_num(op);

    return 0;
}

int main(void) {
    //get_num(getchar());
    printf("%d", ppn(getchar()));
    return 0;
}
