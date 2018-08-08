#include <iostream>
#include "Birthday.h"
#include "People.h"

People::People(string n, Birthday b)
: name(n), dateofbirth(b)
{
	
}

void People::printinfo() {
	cout << name << " was born on ";
	dateofbirth.printDate();
}
