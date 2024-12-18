#include <stdio.h>

//made by: 2cache

int main(void) {

    int n = 0, x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;

    scanf("%d %d %d %d %d %d %d", &n, &x1, &y1, &x2, &y2, &x3, &y3);

    int ps_product1 = x1 * y2 - x2 * y1;
    //printf("%d", ps_product1);
    int ps_product2 = x2 * y3 - x3 * y2;
    //printf("%d", ps_product2);

    int fl = 1;

    if (ps_product1 != ps_product2) fl = 0;
    if (!ps_product1 || !ps_product2) fl = 0;

    ps_product1 = ps_product2;

    x2 = x3;
    y2 = y3;

    for (int i = 0; i < n - 4; i++) {
        scanf("%d %d", &x3, &y3);
        int ps_product2 = x2 * y3 - x3 * y2;
        if (ps_product1 == ps_product2 && fl) {
            x2 = x3;
            y2 = y3;
            ps_product1 = ps_product2;
        }
        else {
            //printf("%d %d %d %d", ps_product1, ps_product2, x1, y1);
            fl = 0;
            continue;
        }
    }

    if (n > 3) scanf("%d %d", &x3, &y3);


    if (fl || n == 3) printf("Yes");
    else printf("No");

    return 0;
}
