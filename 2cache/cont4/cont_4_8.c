#include <stdio.h>
#include <string.h>

//made by: 2cache

int main(void) {
    char input[257] = "";
    int a_pos[257] = {0};
    fgets(input, 257, stdin);
    input[strlen(input) - 1] = 0;
    int i = 0;
    while (input[i] != 0) {
        if (input[i] == 'A') {
            a_pos[i] = 1;
        }
        i++;
    }
    for (int j = 0; j < i; j++) {
        //printf("ind: %d\n", a_pos[j]);
    }

    int r_e = 0, r_o = 0;
    for (int i = 0; i < 256; i++) {
        if (a_pos[i]) {
            if ((i + 1) % 2 == 0) {
                r_o++;
            }
            else {
                r_e++;
            }
        }
    }
    int l_o = 0, l_e = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (a_pos[i]) {
            if ((i + 1) % 2 == 0) {
                r_o--;
            }
            else {
                r_e--;
            }
        } //even == chet

        printf("chet: %d%c%d|nechet:%d%c%d|\n", l_e, (a_pos[i]) ? 'A' : 'B',\
               r_e, l_o, (a_pos[i]) ? 'A' : 'B', r_o);
        if (r_e + l_e == r_o + l_o) {
            //printf("vicherkivaem\n");
            printf("%d ", i + 1);
        }

        if (a_pos[i]) {
            ((i + 1) % 2 == 0) ? l_e++ : l_o++;
        }
    }
    return 0;
}
