#include <iostream>
#include "Sally.h"

using namespace std;

/*
Sally::Sally() {
	cout << "I am the constructor\n";
}
*/

Sally::Sally(int a, int b)
: regVar(a),
constVar(b)
{
}

void Sally::printNums() {
	cout << "Regular var is: " << regVar << endl;
	cout << "Constant var is: " << constVar << endl;
}

Sally::~Sally() {
	cout << "I am the destructor!\n";
}
