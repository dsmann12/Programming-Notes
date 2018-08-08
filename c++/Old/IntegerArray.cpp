#include <iostream> 

using std::cout;
using std::cin;

int main() {

	int myArray[5];
	int i;

	for (i = 0; i < 5; i++) {
		cout << "Value for my array[" << i << "]: ";
		cin >> myArray[i];
	}

	for (i = 0; i < 5; i++) {
		cout << i << ": " << myArray[i] << std::endl;
	}

	return 0;
}