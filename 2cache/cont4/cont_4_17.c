#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

//made by: 2cache

int r_dig(int index, char *s, int len) {
    printf("%d %s %d\n", index, s, len);
    int p = len - 1;
    int num = 0;
    for (int i = 0; i < len ; i++) {
        if (s[i + index] == '1') num += pow(2, p);
        p--;
    }
    return num;
}


static char s[2000002] = "";
static char sc[4000002] = "";

int main(void) {
    fgets(s, 2000002, stdin);

    strcat(sc, s);
    if (sc[strlen(sc) - 1] == '\n') sc[strlen(sc) - 1] = 0;
    strcat(sc, s);
    if (sc[strlen(sc) - 1] == '\n') sc[strlen(sc) - 1] = 0;
    //printf("%s", sc);

    int k = strlen(sc) / 2;
    int fin_index = 0;

    int max_zero = 0;
    int counter_zero = 0;
    int fl = 1;
    for (int i = 0; i < k; i++) {
        counter_zero = 0;
        for (int j = 0 + i; j < k + i; j++) {
            if (!fl) {
                fl = 1;
                continue;
            }
            if (sc[j] == '0') {
                counter_zero++;
                fl = 1;
            }
            else {
                max_zero = MAX(max_zero, counter_zero);
                counter_zero = 0;
                fl = 0;
            }
        }
    }

    fl = 1;
    int min_num = INT_MAX;
    for (int i = 0; i < k; i++) {
        counter_zero = 0;
        for (int j = 0 + i; j < k + i; j++) {
            if (!fl) {
                fl = 1;
                continue;
            }
            if (sc[j] == '0') {
                counter_zero++;
                fl = 1;
            }
            else {
                if (max_zero == counter_zero) {
                    printf("index: %d\n", j);
                    int res = r_dig(j - 2, sc, k);
                    if (res < min_num) {
                        fin_index = j - 2;
                        min_num = res;
                    }
                }
                counter_zero = 0;
                fl = 0;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%c", sc[fin_index + i]);
    }
    printf("\n%d", min_num);
    return 0;
}
