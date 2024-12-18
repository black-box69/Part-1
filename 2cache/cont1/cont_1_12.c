#include <stdio.h>

//made by: 2cache

int main(void){
	int N = 0;
	int max1 = -10000, max2 = -10000, max3 = -10000;
	int a = 0;
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		scanf("%d", &a);
		if (a > max1) {
			max3 = max2;
			max2 = max1;
			max1 = a;
			continue;
		}
		if (a <= max1 && a > max2) {
			max3 = max2;
			max2 = a;
			continue;
		}
		if (a <= max2 && a > max3) {
			max3 = a;
			continue;
		}
	}
	printf("%d %d %d", max1, max2, max3);
	return 0;
}
