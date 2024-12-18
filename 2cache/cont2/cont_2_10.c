#include <stdio.h>
#include <math.h>

//made by: 2cache

int main(void) {
    int n = 0;
    double t = 0.0, tn = 0.0;
    scanf("%d", &n);
    double v1 = 0.0, vn = 0.0;

    double s[100] = {0.0};
    for (int i = 0; i < n; i++) {
        scanf("%lf", &s[i]);
    }

    double a[100] = {0.0};
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    v1 = 2.0 * s[0] * a[0]; // square of second velosity
    tn = sqrt(2.0 * s[0] / a[0]);
    t += tn;

    for (int i = 1; i < n; i++) {
        vn = s[i]*2.0*a[i] + v1; // square of velocity nan
        if ((int) (a[i]*10000) == 0) {
            tn = s[i] / sqrt(vn);
        }
        else {
            tn = (sqrt(vn) - sqrt(v1)) / a[i];
        }
        v1 = vn;
        t += tn;
    }
    printf("%.4lf", t);

    return 0;
}
