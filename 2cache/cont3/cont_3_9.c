#include <stdio.h>
#include <math.h>

//made by: 2cache

void find_coordinates(double ax, double ay, double bx, double by, double cx, double cy) { //вершина, из которой выходит биссектрисса, другие две вершины
    double k = 0.0; //соотношение сторон


    k = sqrt((pow((ax - bx), 2) + pow((ay - by), 2)) / (pow((ax - cx), 2) + pow((ay - cy), 2))); // AB/AC
    double kx = 0.0, ky = 0.0;

    kx = (bx + k*cx) / (1 + k);
    ky = (by + k*cy) / (1 + k);

    printf("%.5lf %.5lf\n", kx, ky);
}

int main(void) {
    double ax = 0.0, ay = 0.0, bx = 0.0, by = 0.0, cx = 0.0, cy = 0.0;

    scanf("%lf", &ax);
    scanf("%lf", &ay);
    scanf("%lf", &bx);
    scanf("%lf", &by);
    scanf("%lf", &cx);
    scanf("%lf", &cy);

    find_coordinates(cx, cy, ax, ay, bx, by);
    find_coordinates(ax, ay, bx, by, cx, cy); //
    find_coordinates(bx, by, cx, cy, ax, ay);


    return 0;
}
