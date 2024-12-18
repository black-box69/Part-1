#include <stdio.h>
#include <stdlib.h>

//made by: CDECL
int main(void)
{
    float x1, y1, x2, y2, x3, y3, x0, y0;
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);
    x0 = (x1 + x2 + x3) / 3;
    y0 = (y1 + y2 + y3) / 3;
    printf("%.4f %.4f", x0, y0);
    return 0;
}
