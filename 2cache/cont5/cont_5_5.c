#include <stdio.h>
#include <stdlib.h>

//made by: 2cache

int main(void) {
    int l = 0;
    scanf("%d", &l);
    char* s123 = (char*) malloc(3 * l * sizeof(char));
    scanf("%s", (s123 + l));
    scanf("%s", (s123) + 2 * l);

    char symbol = s123[l];

    scanf("%s", s123);
    s123[l] = symbol;

    printf("%s", s123);

    free(s123);


    return 0;
}
