#include <iostream>
#include "Ancestor.h"
#include "Descendant.h"

using namespace std;

int main() {
	Ancestor a;
	a.sayName();

	Descendant d;
	d.sayName();
	d.doSomething();
}
