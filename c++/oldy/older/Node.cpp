#include <iostream>
#include "Node.h"
	
using std::string;
using std::cout;
using std::endl;

int main() {
	Node<string> n("David");
	cout << n << endl;

	Node<string> n1;
	cout << n1 << endl;
	n1.setElement("Emily");
	cout << n1 << endl;
	
	Node<int> i;
	cout << i << endl;
	i.setElement(123);
	cout << i << endl;
	
	Node<double> d;
	cout << d << endl;	
	d.setElement(3.14);
	cout << d << endl;
}
