#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE * fp;
	fp = fopen("input.txt", "w");

	fprintf(fp, "I love Emily!\n");
	fprintf(fp, "I love Pepper!\n");

	fclose(fp);

	return 0;
}
