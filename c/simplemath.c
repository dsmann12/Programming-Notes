#include <stdio.h>
#include <stdlib.h>

int main() {
	char name[10];
	int age;

	printf("Enter your name: \n");
	scanf("%s", name);
	printf("What is your age: \n");
	scanf("%d", &age);
	printf("%s is %d years old!\n", name, age);
	printf("In 12 more years, %s will be %d years old!\n", name, age+12);

	return 0;
}
