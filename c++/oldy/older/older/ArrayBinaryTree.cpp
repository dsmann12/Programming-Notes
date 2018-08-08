#include <iostream>
#include <cstdlib>
#include <vector>
#include "Node.h"
#include "BTNode.h"

using namespace std;

//A tree only needs access to root
//From root node, can use node methods to travel

//root
//setRoot()
//inordertraversal
//size
//eurlertraversal
//add(E e)
//add(BTNode<E> &n, E &e)

//Implement Decision Tree
//Implement BST

template <typename E>
class BinaryTree {
	public:
		BinaryTree();
		~BinaryTree();
		BTNode<E> & root();
		void setRoot(const E &e);
		void addLeft(BTNode<E> &p, const E &e);
		void addRight(BTNode<E> &p, const E &e);
		const int size() const;
	private:
		BTNode<E> _root;
		int _size;
		vector<BTNode<E> > tree;
};

template <typename E>
BinaryTree<E>::BinaryTree() {
	_size = 0;
}

template <typename E>
BinaryTree<E>::~BinaryTree() {
	tree.clear();
}

template <typename E>
BTNode<E> & BinaryTree<E>::root() {
	return _root;
}

template <typename E>
void BinaryTree<E>::setRoot(const E &e) {
	_root = *new BTNode<E>(e);
	_size++;
}
template <typename E>
void BinaryTree<E>::addLeft(BTNode<E> &p, const E &e) {
	if(p.hasLeft()) {
		addLeft(p.getLeft(), e);
		return;
	}

	BTNode<E> *n = new BTNode<E>(e);
	p.setLeft(*n);
	_size++;
}

template <typename E>
void BinaryTree<E>::addRight(BTNode<E> &p, const E &e) {
	if(p.hasRight()) {
		addRight(p.getRight(), e);
		return;
	}
	
	BTNode<E> *n = new BTNode<E>(e);
	p.setRight(*n);
	_size++;
}


template <typename E>
const int BinaryTree<E>::size() const {
	return _size;
}

int main() {
	BinaryTree<string> t;
	
	t.setRoot("Left or right");
	BTNode<string> &root = t.root();
	t.addLeft(root, "Left");
	t.addRight(root, "Right");
	
	cout << t.root() << endl;
	string choice;
	cin >> choice;
	if(choice == "Left" && root.hasLeft()) {
		cout << root.getLeft() << endl;
	}
	else if (root.hasRight()) {
		cout << root.getRight() << endl;	
	}
	else {
		cout << "Exception!\n";
	}

	cout << t.size() << endl;
}
