#include <stdio.h>
#include <stdlib.h>

int main() {
	int tuna = 19;
	
	printf("%p \n", &tuna);

	printf("Address \t Name \t Value \n");

	printf("%p \t %s \t %d \n", &tuna, "tuna", tuna);
	
	int * pTuna = &tuna;

	printf("%p \t %s \t %d \n", pTuna, "tuna", tuna);
	
	printf("%p \t %s \t %p \n", &pTuna, "pTuna", pTuna);

	printf("*pTuna is: %d \n", *pTuna);

	*pTuna = 20;

	printf("*pTuna is: %d\n", *pTuna);

	int i;
	int meatBall[5] = {7, 9, 43, 21, 3};

	printf("Element \t Address \t Value \n");
	for(i = 0; i < 5; i++) {
		printf("meatBall[%d] \t %p \t %d \n", i, &meatBall[i], meatBall[i]);
	}

	printf("\nmeatBalls \t\t %p \n", meatBall);

	printf("\n*meatBalls \t\t %d \n", *meatBall);
	printf("\n*(meatBalls+1) \t\t %d \n", *(meatBall + 1));

	return 0;
}
