#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//made by: CDECL

/* 
void debug_matrix_print(long long k, long long** A) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            printf("%lld ", A[i][j]);
        }
        printf("\n");
    }
} 
*/

void matrix_mult(long long k, long long p, long long** A, long long** B, long long** result) {
    long long sum;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            sum = 0;
            for (int s = 0; s < k; s++) {
                sum += A[i][s] * B[s][j] % p;
            }
        result[i][j] = sum % p;
        }
    }
}

void matrix_power(long long k, long long p, long long** A, long long power, long long** result, long long** temp) {
    if (power == 1) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                result[i][j] = A[i][j] % p;
            }
        }
        return;
    }
    else if (power == 0) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                result[i][j] = 0;
                if (i == j) result[i][j] = 1;
            }
        }
        return;
    }
    if (power % 2 == 0) {
        matrix_power(k, p, A, power / 2, temp, result);
        matrix_mult(k, p, temp, temp, result);
    }
    else {
        matrix_power(k, p, A, power - 1, temp, result);
        matrix_mult(k, p, temp, A, result);
    }
}

int main(void) {
    long long k, N, p;
    scanf("%lld%lld%lld", &k, &N, &p);
    
    long long *F = calloc(k, sizeof(long long));
    for (int i = k - 1; i >= 0; i--) {
        scanf("%lld", &F[i]);
    }
    
    long long **A, **result, **temp;
    A = calloc(k, sizeof(long long*));
    for (int i = 0; i < k; i++) {
        A[i] = calloc(k, sizeof(long long));
    }
    temp = calloc(k, sizeof(long long*));
    for (int i = 0; i < k; i++) {
        temp[i] = calloc(k, sizeof(long long));
    }
    result = calloc(k, sizeof(long long*));
    for (int i = 0; i < k; i++) {
        result[i] = calloc(k, sizeof(long long));
    }
    for (int i = 0; i < k - 1; i++) {
        scanf("%lld", &A[0][i]);
        A[i + 1][i] = 1;
    }
    scanf("%lld", &A[0][k - 1]);
    
    if (N <= k) {
      printf("%lld", F[k - N] % p);
    }
    else {
      long long ans = 0;
      matrix_power(k, p, A, N - k, result, temp);
      // debug_matrix_print(k, result);
      for (int i = 0; i < k; i++) {
          ans += result[0][i] * F[i] % p;
      }
      printf("%lld", ans % p);
    }
    return 0;
}
