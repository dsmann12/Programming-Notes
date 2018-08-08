#include <stdio.h>
#include <stdlib.h>

struct user {
	int userID;
	char firstname[20];
	int age;
};

int main() {
	struct user david;
	
	printf("What is you userID: \n");
	scanf("%d", &david.userID);
	printf("What is your name: \n");
	scanf("%s", david.firstname);
	printf("What is your age: \n");
	scanf("%d", &david.age);

	printf("User %d %s is %d years old!\n", david.userID, david.firstname, david.age);

	return 0;
}
