#include <iostream>
#include <cstdlib>
#include <vector>
#include "Node.h"
#include "TNode.h"

int main() {
	TNode<string> n;
	TNode<string> p;

	n.setElement("David III");
	p.setElement("Martina Teran");

	cout << "P is " << p.getElement() << endl;
	cout << "N is " << n.getElement() << endl;
	
	p.addChild(n);
	n.setParent(p);
	
	if(n.isExternal()) {
		cout << "N is external!\n";
	}
	
	if(p.isExternal()) {
		cout << "P is external!\n";
	}
	
	if(p.isInternal()) {
		cout << "P is internal!\n";
	}
	
	TNode<string> &parent = n.getParent();
	cout << "Parent is " << parent.getElement() << endl;
	
	p.setIndex(0);
	n.setIndex(1);
	
	cout << "P index is " << p.getIndex() << endl;
	cout << "N index is " << n.getIndex() << endl;
	
	TNode<string> &pchild = p.getChild(0);
	
	cout << "Pchild is " << pchild.getElement() << endl;
	
	TNode<string> &nparent = n.getParent();
	
	cout << "nparent is " << nparent.getElement() << endl;
}
