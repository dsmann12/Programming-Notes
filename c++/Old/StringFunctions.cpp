#include <iostream>
#include <string.h>

using namespace std;

int main() {

	char String1[] = "No man is an island.";
	char String2[80] = { '\0' };

	strcpy(String2, String1);

	cout << "String1: " << String1 << endl;
	cout << "String2: " << String2 << endl;

	const int MaxLength = 80;
	char String3[] = "Stop repeating what I say.";
	char String4[MaxLength+1] = { '\0' };

	strncpy(String4, String3, MaxLength);

	cout << "String3: " << String3 << endl;
	cout << "String4: " << String4 << endl;
	
	return 0;
}