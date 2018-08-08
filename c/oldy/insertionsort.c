#include <stdlib.h>
#include <stdio.h>

int main() {
	int a[10];
	for(int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}

	printf("[%d", a[0]);
	for(int i = 1; i < 10; i++) {
		printf(", %d", a[i]);
	}
	printf("]\n");

	for(int i = 1; i < 10; i++) {
		int cur = i;
		for(int j = i - 1; j >= 0; j--) {
			if(a[cur] < a[j]) {
				int temp = a[cur];
				a[cur] = a[j];
				a[j] = temp;
				cur = j;
			}
		}
	}

	printf("[%d", a[0]);
	for(int i = 1; i < 10; i++) {
		printf(", %d", a[i]);
	}
	printf("]\n");
	return 0;
}
