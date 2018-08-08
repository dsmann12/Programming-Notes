#include <stdio.h>
#include <stdlib.h>

int main() {
	char movie[20];
	char *pMovie = movie; 

	//what if more than 20 characters are entered?

	fgets(pMovie, 20, stdin);
	puts(pMovie);

	return 0;
}

