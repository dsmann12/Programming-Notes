#include <iostream> 

using namespace std;

int Add(int first, int second) {
	cout << "Add() received " << first << " and " << second << endl;
	return (first + second);
}

int main() {
	cout << "I'm in main()!\n";
	int a, b, c;
	cout << "Enter two numbers: ";
	cin >> a;
	cin >> b;
	cout << "Calling Add().\n";
	c = Add(a, b);
	cout <<"\nBack in main().\n";
	cout << "c was set to " << c << endl;
	cout << "Exiting...\n\n";
	return 0;
}