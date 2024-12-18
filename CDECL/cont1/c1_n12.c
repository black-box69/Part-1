#include <stdio.h>
#include <stdlib.h>

//made by: CDECL
int main(void)
{
    int N, m1, m2, m3, h, k;
    scanf("%d", &N);
    scanf("%d%d%d", &m1, &m2, &m3);
    if (m3 > m2) {
        h = m2;
        m2 = m3;
        m3 = h;
    }
    if (m2 > m1) {
        h = m1;
        m1 = m2;
        m2 = h;
    }
    if (m3 > m2) {
        h = m2;
        m2 = m3;
        m3 = h;
    }
    for (int i = 0; i < N - 3; i++) {
        scanf("%d", &k);
        if (k >= m1) {
            m3 = m2;
            m2 = m1;
            m1 = k;
        }
        else if (k >= m2) {
            m3 = m2;
            m2 = k;
        }
        else if (k >= m3) {
            m3 = k;
        }
    }
    printf("%d %d %d\n", m1, m2, m3);
    return 0;
}
