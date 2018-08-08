#include <stdio.h>

int main()
{
	int a,b;

	printf("Type two letters: ");
	a = getchar();
	b = getchar();
	/*printf("You typed '");
	putchar(a);
	printf("' and '");
	putchar(b);
	printf("'.\n"); */

	printf("You typed '%c' and '%c.'\n", a, b);

	return(0);
}

