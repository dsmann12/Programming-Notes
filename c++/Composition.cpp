#include <iostream>
#include "Birthday.h"
#include "People.h"

using namespace std;

int main() {
	Birthday bobj(1, 23, 1992);
	People dave("David", bobj);

	dave.printinfo();
}
