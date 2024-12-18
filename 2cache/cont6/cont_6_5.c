#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//made by: 2cache

int count_digits (char *p) {
    int k = 0;
    while (*p - '0' <= 9 && *p - '0' >= 0) {
        k++;
        p++;
    }
    return k;
}


long long int digitalize (char *p) {
    long long int res = 0;
    while (*p - '0' <= 9 && *p - '0' >= 0) {
        res *= 10;
        res += *p - '0';
        p++;
    }
    return res;
}


int main(void) {
    FILE *f = fopen("input.txt", "r");
    FILE *fp = fopen("input.txt", "r");
    fseek(fp, 0L, SEEK_END); //was adapted from stack overflow
    long long int size = ftell(fp);
    size -= 1;
    char * buffer = malloc(sizeof(char) * size);
    fread(buffer, 1, size, f);

    // don't use f

    char * p = buffer;
    long long int res = 0;
    int fl = 1;
    for (int i = 0; i < size; i++) {
        if (p[i] == '-') {
            fl = 0;
            //i++;
        }
        else if (p[i] == '+') {
            fl = 1;
            //i++;
        }
        else if (p[i] - '0' <= 9 && p[i] - '0' >= 0) {
            if (fl) res += digitalize(p + i);
            else if (!fl) res -= digitalize(p + i);
            i += count_digits(p + i) - 1;
        }
    }
    fclose(f);
    fclose(fp);
    free(buffer);



    FILE *f_new = fopen("output.txt", "w");
    fprintf(f_new, "%lld", res);
    fclose(f_new);
    return 0;
}
