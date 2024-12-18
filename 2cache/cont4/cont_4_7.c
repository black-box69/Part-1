#include <stdio.h>

//made by: 2cache

int combinations() {
	
}

int main(void) {
	int n = 0;
	scanf("%d", &n);
	char list_of_cities[10][21] = {""};
	for (int i = 0; i < n + 1; i++) {
		fgets(list_of_cities[i], 21, stdin);
	}

	return 0;
}
