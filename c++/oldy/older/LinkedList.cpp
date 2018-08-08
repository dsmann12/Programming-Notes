#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::string;
using std::endl;

int main() {
	LinkedList<string> ll;
	ll.addFront("David");
	
	cout << ll.front() << endl;
	ll.addFront("Emily");
	ll.addFront("Martina");
	ll.addFront("Ashleigh");

	cout << "\nPrinting -----\n";	
	ll.print();

	LinkedList<string> l1;
	
	l1.addLast("Emily");
	l1.addLast("David");
	l1.addFront("Martina");
	l1.addFront("Ashleigh");
	l1.addLast("Bradley");
	
	cout << "\nPrinting\n";
	l1.print();

	cout << "Front in ll is " << ll.front() << endl;
	cout << "Last in ll is " << ll.last() << endl;
	cout << "Front in l1 is " << l1.front() << endl;
	cout << "Last in l1 is " << l1.last() << endl;
	
}
