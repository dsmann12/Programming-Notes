#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE * fPointer;
	fPointer = fopen("bacon.txt", "r");

	char singleLine[4096];

	while(!feof(fPointer)) {
		fgets(singleLine, 4096, fPointer);
		puts(singleLine); 		
	}

	fclose(fPointer);

	return 0;
}
