#include <stdio.h>
#include <stdlib.h>

int main() {
	int * points; //integer pointers points to first item in heap
	points = (int *) malloc(5 * sizeof(int));

	free(points);

	return 0;
}
