#include <stdio.h>

//made by: 2cache

int main(void){
	int N = 0;
	int max = -1000000;
	int min = 1000000;
	int a = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &a);
		if (a > max){
			max = a;
		}
		if (a < min){
			min = a;
		}
	}
	printf("%d", max-min);
	return 0;
}
