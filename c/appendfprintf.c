#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE * fp;
	fp = fopen("input.txt", "a");

	fprintf(fp, "\n- a hikewl by David Scheuermann\n");

	fclose(fp);

	return 0;
}
