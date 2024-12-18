#include <stdio.h>

//made by: 2cache

int main(void) {
    unsigned long a11 = 0, a12 = 0, a21 = 0, a22 = 0, b1 = 0, b2 = 0;

    scanf("%lu", &a11);
    scanf("%lu", &a12);
    scanf("%lu", &a21);
    scanf("%lu", &a22);
    scanf("%lu", &b1);
    scanf("%lu", &b2);

    unsigned long x = 0;
    unsigned long y = 0;
    int abnormal = 0;
    int counter = 0;

    for (int i = 31; i >= 0; i--) {
        unsigned bit_a11 = ((a11 >> i) & (unsigned) 1);
        unsigned bit_a12 = ((a12 >> i) & (unsigned) 1);
        unsigned bit_a21 = ((a21 >> i) & (unsigned) 1);
        unsigned bit_a22 = ((a22 >> i) & (unsigned) 1);
        unsigned bit_b1 = ((b1 >> i) & (unsigned) 1);
        unsigned bit_b2 = ((b2 >> i) & (unsigned) 1);


        int err = 0;
        for (int bit_x = 0; bit_x < 2; bit_x++) {
            int solution = 0;
            for (int bit_y = 0; bit_y < 2; bit_y++) {
                int cond1 = (((bit_a11 & bit_x) ^ (bit_a12 & bit_y)) == bit_b1);
                int cond2 = (((bit_a21 & bit_x) ^ (bit_a22 & bit_y)) == bit_b2);
                if (cond1 && cond2) {
                    x = (x << 1) + bit_x;
                    y = (y << 1) + bit_y;
                    //printf("a11: %u| x: %u| a12: %u| y: %u| b1: %u|\n", bit_a11, bit_x, bit_a12, bit_y, bit_b1);
                    //printf("a21: %u| x: %u| a22: %u| y: %u| b2: %u|\n", bit_a21, bit_x, bit_a22, bit_y, bit_b2);
                    solution = 1;
                    counter++;
                    break;
                }
                else if (bit_y < 1) continue;
                else err = 1;
            }
            err *= bit_x;
            if (solution) break;
        }
        if (err) {
            abnormal = 1;
            break;
        }
    }
    //printf("%d", counter);
    if (abnormal) printf("No");
    else printf("Yes\n%lu %lu", x, y);























































    /*
    for (int i = 31; i >= 0; i--) {
        if (drop) {
            printf("Dropped");
            break;
        }
        unsigned bit_a11 = ((a11 >> i) << 31) >> 31;
        unsigned bit_a12 = ((a12 >> i) << 31) >> 31;
        unsigned bit_a21 = ((a21 >> i) << 31) >> 31;
        unsigned bit_a22 = ((a22 >> i) << 31) >> 31;
        unsigned bit_b1 = ((b1 >> i) << 31) >> 31;
        unsigned bit_b2 = ((b2 >> i) << 31) >> 31;

        int success = 0;
        for (unsigned bit_x = 0; bit_x < 2; bit_x++) {
            for (unsigned bit_y = 0; bit_y < 2; bit_y++) {
                if (((bit_a11 & bit_x) ^ (bit_a12 & bit_y)) == bit_b1 && ((bit_a21 & bit_x) ^ (bit_a22 & bit_y)) == bit_b2) {
                    x = (x << 1) + bit_x;
                    y = (y << 1) + bit_y;
                    success = 1;
                    break;
                }
                if (success) break;
                if (bit_y && !success) drop = 1;
            }
            if (bit_x && !success) drop = 1;
        }

    }

    if (!drop) printf("Yes\n%lu %lu", x, y);
    else printf("No");
    */

    return 0;
}
