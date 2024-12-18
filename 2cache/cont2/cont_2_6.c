#include <stdio.h>

//made by: 2cache

int main(void) {
    int m[10000] = {0};
    int m_[10000] = {0};
    int m_2[10000] = {0};
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }

    for (int i = 0; i < n; i++) {
        m_[i] = m[m[i] - 1];
    }

    for (int i = 0; i < n; i++) {
        m_2[i] = m[m_[i] - 1];
        printf("%d ", m_2[i]);
    }


    return 0;
}
