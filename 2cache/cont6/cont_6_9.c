#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//made by: 2cache

// 1 2 3 4 5 6 7 1 2 3 4 5 6 7
// 4 5 6 7 1 2 3
// 4 5 6 1 2 3 7 -- correct
//////////////////////////////
// 4 5 6 1 2 3 7 | 4 5 6 1 2 3 7
// 5 6 1 2 4 3 7

/*
1 1 1 1 0 0
0 1 1 1
*/
int check_tree(int * p, int len) { // reversed
    //printf("%c\n", p[0]);
    //printf("%d", p[1]);
    if (len == 0 && (p[0] == '\n' || p[0] == 0)) { //?
        //printf("terminated\n");
        return 0;
    }
    int fl = 2;
    //int probability = 2;
    int i = 0;
    //printf("len : %d\n", len);
    if ((2 * i + 1) < len) { // left son exists
        //printf("turned left son...\n"); // p[i] <= p[2i + 1] -- 1
        if (p[i] <= p[2 * i + 1]) {
            //printf("built 1 tree\n");
            fl = 1;
        }
        else if (p[i] >= p[2 * i + 1]) {
            //printf("built -1 tree\n");
            fl = -1;
        }
    }
    if (fl == 2) {
        //printf("process terminated\n");
        return 1; // one num not pyramid
    }

    //printf("%d", fl);
    if ((2 * i + 2) < len) { //right son exists
        if (fl == -1) {
            if (p[i] < p[2 * i + 2]) {

                return 0;
            }
        }
        else if (fl == 1) {
            if (p[i] > p[2 * i + 2]) {
                return 0;
            }
        }
    }

    //printf("skipped right son termination...\n");

    for (i = 2 * i + 1; i < len; i++) {
        //printf("i: %d\n", i);
        if ((2 * i + 1) < len) {
            if (fl == -1) {
                if (p[i] < p[2 * i + 1]) {
                    //printf("process terminated on left son with flag 1\n");
                    return 0;
                }
            }
            else if (fl == 1) {
                if (p[i] > p[2 * i + 1]) {
                    //printf("process terminated on left son with flag -1\n");
                    return 0;
                }
            }
        }
        else continue;
        if ((2 * i + 2) < len) {
            if (fl == -1) {
                if (p[i] < p[2 * i + 2]) {
                    //printf("curr i: %d\nlen: %d\n", 2 * i + 2, len);
                    //printf("process terminated on right son with flag 1\n");
                    return 0;
                }
            }
            else if (fl == 1) {
                if (p[i] > p[2 * i + 2]) {
                    //printf("process terminated on right son with flag -1\n");
                    return 0;
                }
            }
        }
        else continue;

    }
    return fl;
}

int main(void) {
    char name[] = "input.bin"; //!
    FILE *f = fopen(name, "rb");
    int max_len = 132000;

    int nums[132000] = {0};



    int len = fread(nums, sizeof(int), max_len, f);
    fclose(f);


    /*int nums[] = {16, 11, 9, 10, 57, 6, 8, 1, 2, 4};
    int len = 10;
    printf("%d", res);
    */

    int res = check_tree(nums, len);

    f = fopen("output.bin", "wb");
    fwrite(&res, sizeof(int), 1, f);


    //printf("%d", res);
    return 0;
}
