#include <iostream>

using namespace std;

int main() {

	long TargetArray[25];

	int i;

	for (i = 0; i < 25; i++) {
		TargetArray[i] = 10;
	}

	cout << "Test 1: \n"; // Test current values (should be 0)
	cout << "TargetArray[0]: " << TargetArray[0] << endl; //lower bound
	cout << "TargetArray[24: " << TargetArray[24] << endl; //upper bound

	cout << "\nAttempting at assigning values beyoind the upper-bound...";

	for (i = 0; i <=25; i++) {
		TargetArray[i] = 20; //should fail at element [25]
	}

	cout << "\nTest 2: \n";
	cout << "TargetArray[0]: " << TargetArray[0] << endl;
	cout << "TargetArray[24}: " << TargetArray[24] << endl;
	cout << "TargetArray[25]: " << TargetArray[25] << endl << endl;

	return 0;
}