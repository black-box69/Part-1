#include <stdio.h>
#include <math.h>

//made by: 2cache

//the formula in (*) https://www.jstor.org/stable/2310398
int main(void)
{
    double A = 0, B = 0, a = 0, b = 0;

    scanf("%lf %lf %lf %lf", &A, &B, &a, &b);
    if (B > A) {
        double temp = A;
        A = B;
        B = temp;
    }
    if (b > a) {
        double temp = b;
        b = a;
        a = temp;
    }

    if (A >= a && B >= b) printf("YES"); //first case (*)
    else if (a > A && !(B < (2 * a * b * A + ((pow(a, 2) - pow(b, 2)) * sqrt(pow(a, 2) + pow(b, 2) - pow(A, 2)))) / (pow(a, 2) + pow(b, 2)))) printf("YES"); // (*)
    else printf("NO");

    return 0;
}
