#include <stdio.h>
#include <stdlib.h>

//made by: 2cache

int main(void) {
	int m = 0x0;
	int res = 0x0;
	scanf("%x", &m);
	for (int i = 0; i < 16; i++) {
		if (m%2) {
			res += 1 << (i%4) * 4 + (i / 4));
		}
		m >>= 1;
	}
	if (res >> 12 == 0) {
		printf("%d", 0);
		if (res >> 8 == 0) {
			printf("%d", 0);
			if (res >> 4 == 0) {
				printf("%d", 0);
			}
		}
	}
	printf("%x", res);
}
