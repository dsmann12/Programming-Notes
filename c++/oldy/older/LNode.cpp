#include <iostream>
#include "LNode.h"

using std::string;
using std::cout;
using std::endl;

int main() {
	LNode<string> n("David");
	cout << n << endl;

	LNode<string> n1 = LNode<string>();
	cout << n1 << endl;
	
	n1.setElement("Emily");
	cout << n1 << endl;
	
	n.setNext(&n1);

	LNode<string> &np = *n.next();	

	cout << n << endl;
	cout << np << endl;
	cout << *(n.next()) << endl;
	
	
}
