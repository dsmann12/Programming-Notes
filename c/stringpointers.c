#include <stdio.h>
#include <stdlib.h>

int main() {
	char movie[] = "Movie Title";
//	movie = "New Title"; illegal expression
	char *movie2 = "The Best Movie";

	puts(movie2);
	
	movie2 = "New Movie Title";
	
	puts(movie2);

	return 0;
}
