#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;

int main() {
	Node<string> n;
	Node<string> n1("Emily");
	
	Node<int> ni;

	string s = n1.getElement();
	cout << "s is " << s << endl;
	string s1 = n.getElement();
	cout << "s1 is " << s1 << endl;

	n.setElement("David");
	s1 = n.getElement();
	cout << "s1 now is " << s1 << endl;

	cout << "Can i just print the element " << n.getElement() << endl;
}
