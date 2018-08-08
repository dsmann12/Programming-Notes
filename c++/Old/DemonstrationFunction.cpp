#include <iostream>

//function Demonstration function
//prints out a useful message
using namespace std;

void DemonstrationFunction() {
	cout << "In Demonstration Function.\n";
}

int main() {
	cout << "In main.\n";
	DemonstrationFunction();
	cout << "Back in main.\n";
	return 0;
}