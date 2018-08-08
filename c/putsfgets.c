#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char catsName[50];
	char catsFood[25];
	char sentence[75] = "";

	puts("What's the cat's name? ");
	fgets(catsName);

	puts("What does she eat? ");
	fgets(catsFood);

	strcat(sentence, catsName);
	strcat(sentence, " loves to eat ");
	strcat(sentence, catsFood);

	puts(sentence);

	return 0;
}
