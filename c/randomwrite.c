#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE * fp;
	fp = fopen("append.txt", "w+");
	fputs("I love Pepper so much!", fp);

	fseek(fp, 7, SEEK_SET);
	fputs("Emily!", fp);

	fseek(fp, -9, SEEK_END);
	fputs("more than anything!", fp);
	fclose(fp); 
	return 0;
}
