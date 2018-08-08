#include <iostream>
#include <cstdlib>
#include "TNode.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	TNode<string> root("/");
	TNode<string> bin("bin");
	TNode<string> etc("etc");
	TNode<string> dev("dev");
	TNode<string> proc("proc");
	TNode<string> home("home");
	TNode<string> david("david");
	
	cout << david << endl;
	cout << root << endl;
	
	root.addChild(bin);
	root.addChild(etc);
	root.addChild(dev);
	root.addChild(proc);
	
	cout << *root.child(0) << endl;
	cout << *root.child(1) << endl;
	
	root.addChild(home);
	root.child(4)->addChild(david);
	
	cout << *root.child(4) << endl;
	cout << *root.child(4)->child(0) << endl;
	
	for(int i = 0; i < root.children().size(); i++) {
		cout << *root.child(i) << endl;
	}
}
