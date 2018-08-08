#include <cstdlib>
#include <iostream>

#include "BTree.h"

using namespace std;

int main() {
	BTree<int> t;
	
	BTNode<int> &root = t.root();

	t.insert(44);
	t.insert(17);
	t.insert(32);
	t.insert(28);
	t.insert(29);
	t.insert(88);
	t.insert(65);
	t.insert(97);
	t.insert(54);
	t.insert(82);
	t.insert(76);
	t.insert(80);
	t.insert(78);
	cout << root << endl;
	cout << *root.left() << endl;
	cout << *root.right() << endl;

	cout << *root.left()->left() << endl;
	cout << *root.left()->right() << endl;

	t.remove(65);
	cout << *root.right()->left() << endl;
	cout << *root.right()->left()->right()->left() << endl;

	cout << t.height(&root) << endl;
	cout << root << endl;
	cout << root.isExternal() << endl;

	cout << endl;
	
	t.print(t.root(), 0);
	t.remove(44);
	cout << endl << endl;
	t.print(t.root(), 0);
	t.remove(54);
	t.remove(88);
	t.remove(28);
	cout << endl << endl;
	t.print(t.root(), 0);

	while(t.root().isInternal()) {
		t.remove(t.root().element());
		
		cout << endl << endl;
		t.print(t.root(), 0);
	}
	
}
