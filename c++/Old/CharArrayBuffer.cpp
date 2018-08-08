#include <iostream>

using namespace std;

int main() {

	char buffer[80] = { '\0' };

	cout << "Enter the string: ";
	cin.get(buffer, 79); //get up to 79 or newline
	cout << "Here's the buffer: " << buffer << std::endl;

	return 0;
}