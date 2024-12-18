#include <stdio.h>

//made by: 2cache

int main(void) {
    int n = 64;
    int p[10][10] = {0};
    //printf("%d", sizeof(char));
    char input[128] = "";
    scanf("%s", input);


    for (int i = 0; i < 127; i++) {
        int x = input[i] - 'a' + 1, y = input[i+1] - '1' + 1;
        p[x][y] = 1;
        p[x - 1][y - 1] = 1;
        p[x][y - 1] = 1;
        p[x + 1][y - 1] = 1;
        p[x + 1][y] = 1;
        p[x + 1][y + 1] = 1;
        p[x][y + 1] = 1;
        p[x - 1][y + 1] = 1;
        p[x - 1][y] = 1;
    }

    for (int x = 1; x < 9; x++) {
        //printf("\n");
        for (int y = 1; y < 9; y++) {
            //printf("%d", p[x][y]);
            n -= p[x][y];
        }
    }
    printf("%d", n);
    return 0;

}
