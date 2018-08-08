#include <iostream>
#include <cstdlib>
#include "Deque.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	Deque<string> d;
	d.addFront("Emily");
	d.addLast("Bradley");
	
	d.print();
	
	cout << "First is " << d.front() << endl;
	cout << "Last is " << d.last() << endl;
	
	d.addFront("David");
	
	cout << endl;
	d.print();
	cout << "size is " << d.size() << endl;
}
