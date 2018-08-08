#include <iostream>

using namespace std; 

int main() {
	int a = 20000;
	char c = a;
	int b = c;

	if (a != b)
		cout << "oops!: " << a << "!= " << b << endl;
	else
		cout << "Wow! We have large characters!";
}
