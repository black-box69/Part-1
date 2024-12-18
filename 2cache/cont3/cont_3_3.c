#include <stdio.h>
void f(void);

//made by: 2cache

void f(void) {
    int s = 0;
    scanf("%d", &s);
    if (s == 0) return ;
    f();
    printf("%d ", s);

}

int main(void) {
    f();
}
