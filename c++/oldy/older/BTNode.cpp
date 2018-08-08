#include <iostream>
#include <cstdlib>
#include "BTNode.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	BTNode<string> *root = new BTNode<string>("root");
	BTNode<string> *l = new BTNode<string>("l");
	BTNode<string> *r = new BTNode<string>("r");
	BTNode<string> *ll = new BTNode<string>("ll");
	BTNode<string> *lr = new BTNode<string>("lr");
	BTNode<string> *rl = new BTNode<string>("rl");
	BTNode<string> *rr = new BTNode<string>("rr");

	root->setLeft(*l);
	root->setRight(*r);
	
	cout << *root << endl;
	cout << *(root->left()) << endl;
	cout << *(root->right()) << endl;

	l->setLeft(*ll);
	l->setRight(*lr);

	cout << endl;
	cout << *(l->left()) << endl;
	cout << *(l->right()) << endl;
	
	cout << endl;
	cout << *root->left()->left() << endl;
	cout << *root->left()->right() << endl;
	
	
}
