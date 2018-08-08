#include <iostream>
#include "DLNode.h"

using std::string;
using std::cout;
using std::endl;

int main() {
	DLNode<string> n("David");
	cout << n << endl;
	
	DLNode<string> n1("Emily");
	DLNode<string> n0("Martina");
	
	DLNode<string> e;
	cout << e << endl;
	
	n.setPrev(&n0);
	n.setNext(&n1);
	
	cout << *n.prev() << endl;
	cout << *n.next() << endl;
}
