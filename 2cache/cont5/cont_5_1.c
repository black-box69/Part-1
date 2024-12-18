#include <stdio.h>
#include <stdlib.h>

//made by: 2cache

int main(void) {
    int n = 0;
    scanf("%d", &n);

    long** real = (long**) malloc(n * sizeof(long*));
    long** image = (long**) malloc(n * sizeof(long*));





    for (int i = 0; i < n; i++) {
        real[i] = (long*) malloc(n * sizeof(long));
        image[i] = (long*) malloc(n * sizeof(long));
        for (int j = 0; j < n; j++) {
            scanf("%ld", &real[i][j]);
            scanf("%ld", &image[i][j]);
         }
    }

    for (int i = 0; i < n; i++) { //transp + conjugate
        for (int j = i; j < n; j++) {
            long buf = real[i][j];
            real[i][j] = real[j][i];
            real[j][i] = buf;
            buf = image[i][j];
            image[i][j] = - image[j][i];
            image[j][i] = - buf;
        }
    }
    //
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < n; j++) {
    //        printf("%d", real[i][j]);
    //    }
    //    printf("\n");
    //}
    //

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%ld %ld ", real[i][j], image[i][j]);
        }
        printf("\n");
    }

    // free memory

    for (int i = 0; i < n; i++) {
        free(real[i]);
        free(image[i]);
    }
    free(real);
    free(image);

    return 0;
}
