#include <iostream>
#include <cstdlib>
#include "TNode.h"
#include "Tree.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	Tree<string> t;

	t.addNode("/");

	cout << t.size() << endl;

	t.preorderprint(0, t.root());
	
	t.addNode("bin");
	t.addNode("etc");
	t.addNode("sys");
	t.addNode("proc");
	t.addNode("usr");
	t.addNode("home");
	t.addNode("var");

	t.preorderprint(0, t.root());

	cout << endl;
	TNode<string> &home = *t.root().child(5);
	TNode<string> &bin = *t.root().child(0);
	TNode<string> &usr = *t.root().child(4);
	TNode<string> &etc = *t.root().child(1);

	t.addNode(home, "david");
	t.addNode(*home.child(0), "Documents");
	t.addNode(bin, "bash");
	t.addNode(usr, "local");
	t.addNode(usr, "sbin");
	t.addNode(etc, "apt");
	t.addNode(etc, "python");


	t.preorderprint(0, t.root());
	
	cout << endl;

	t.postorderprint(0, t.root());

	cout << t.depth(t.root()) << endl;
	cout << "Depth of Node: " << *home.child(0) << " is: "
			<< t.depth(*home.child(0)) << endl;

	cout << t.height(t.root()) << endl;

	t.bfsprint();
}
