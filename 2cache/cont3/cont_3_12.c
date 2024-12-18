#include <stdio.h>
#define MAX(A, B) (A > B) ? A : B

//made by: 2cache

int distribution(int i, int s1, int s2, int total, int *arr) {
    if (i == total) {
        if ((s1 == 0) || (s2 == 0)) { // all numbers are distributed; have empty arr
            return 0;
        }
        else if (s1 == s2) { // all numbers are distributed; have max sum
            return s1;
        }
        else {
            return 0;
        }
    }
    else { // distribute numbers (first arr, second arr, none of them)
        int branch1 = distribution(i + 1, s1 + *(arr + 1), s2, total, arr + 1);
        int branch2 = distribution(i + 1, s1, s2 + *(arr + 1), total, arr + 1);
        int branch3 = distribution(i + 1, s1, s2, total, arr + 1);
        return MAX(MAX(branch1, branch2), branch3);
    }

}

int main(void) {
    int n = 0;

    int all_nums[14] = {0};

    scanf("%d", &n);

    for (int i = 1; i < n + 1; i++) {
        scanf("%d", &all_nums[i]);
    }
    int res = distribution(0, 0, 0, n, all_nums);
    printf("%d", res);
    return 0;
}
