#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "BTNode.h"

using namespace std;

int main() {
	BTNode<string> n("David");
	BTNode<string> n1;
	
	n1.setElement("Emily");
	
	cout << n.getElement() << endl;
	cout << n1.getElement() << endl;
	
	cout << endl << "Ostreams\n";
	
	cout << n << endl;
	cout << n1 << endl;
	
	BTNode<string> root ("/");
	BTNode<string> usr("usr");
	BTNode<string> bin("bin");
	BTNode<string> home("home");
	BTNode<string> etc("etc");
	BTNode<string> david("david");
	BTNode<string> documents("documents");
	BTNode<string> downloads("downloads");
	BTNode<string> videos ("videos");
	
	root.setLeft(usr);
	root.setRight(bin);
	
	cout << bin.getParent() << endl;
	cout << root.getLeft() << endl;
	cout << root.getRight() << endl;
	
	cout << "\nLet's get some indexes!\n";
	cout << "root: " << root.getIndex();
	cout << "\nleft: " << root.getLeft().getIndex();
	cout << "\nright: " << root.getRight().getIndex() << endl;
}
