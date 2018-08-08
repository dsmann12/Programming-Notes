#include <iostream>
#include "OpOverload.h"

using namespace std;

int main() {
	OpOverload a(34);
	OpOverload b(21);
	OpOverload c;

	c = a + b;

	cout << c.num << endl;
}
