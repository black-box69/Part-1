#include <stdio.h>
#define MAX(A, B) (A > B) ? A : B

//made by: 2cache

int main(void)  {
    int n = 0;
    scanf("%d", &n);
    int p1 = 0, p2 = 0;
    scanf("%d", &p1);
    int k = 1;
    int m = 1;
    for (int i = 0; i < n-1; i++) {
        scanf("%d", &p2);
        if (p2 > p1) {
            k++;
            m = MAX(k, m);
        }
        else k = 1;
        p1 = p2;
    } 
    printf("%d", m);
    return 0;
}
