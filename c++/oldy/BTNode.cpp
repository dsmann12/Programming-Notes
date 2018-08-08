#include <cstdlib>
#include <iostream>
#include "BTNode.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	BTNode<string> *root = new BTNode<string>("root");
	BTNode<string> *l = new BTNode<string>("l");
	BTNode<string> *r = new BTNode<string>("r");

	cout << *root << endl;

	root->setLeft(l);
	root->setRight(r);
	
	cout << "Right: " << *root->right() << endl;
	cout << "Left: " << *root->left() << endl;

	cout << root->hasLeft() << endl;
	cout << root->hasRight() << endl;
	cout << root->isInternal() << endl;
	cout << root->isExternal() << endl;
	cout << l->isInternal() << endl;
	cout << r->isInternal() << endl;
	cout << l->isExternal() << endl;
	cout << r->isExternal() << endl;
	cout << root->isRoot() << endl;
	cout << r->isRoot() << endl;
}
