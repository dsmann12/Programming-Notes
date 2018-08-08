#include <iostream>
#include "Sally.h"

using namespace std;

Sally::Sally() {
	cout << "I am the constructor!\n";
}

Sally::~Sally() {
	cout << "I am the deconstructor!\n"; //runs when object is destroyed
	//objects destroyed automatically by C++ at end of program they are created
}
