#include <iostream>
#include <cstdlib>
#include <vector>
#include "Node.h"
#include "TNode.h"
#include "Queue.h"

using namespace std;


//Private
//root
//size
//?vector of nodes
//Public
//Tree()
//~Tree()
//getRoot()
//setRoot()
//getSize()
//setSize()
//getNodes()
//isEmpty()

//return reference to created node?
//addNode(E e)
//addNode(Node p, E e)
//addNode(Node p, Node n)
//addNode(Node n)
template <typename E>
class Tree {
	public:
		Tree();
		~Tree();
		void setRoot(const TNode<E> &n);
		TNode<E> & getRoot();
		TNode<E> & addNode(const E &e);
		TNode<E> & addNode(TNode<E> &p, const E &e);
		bool isEmpty() const;
		const int depth(TNode<E> &n) const;
		const int height(TNode<E> &n) const;
		void preorderprint(const int i, TNode<E> &n) const;
		void postorderprint(const int i, TNode<E> &n) const;
		void breadthfirstprint() const;
	private:
		TNode<E> root;
		int size;
};

template <typename E>
Tree<E>::Tree() {
	size = 0;
}

template <typename E>
Tree<E>::~Tree() {}

template <typename E>
void Tree<E>::setRoot(const TNode<E> &n) {
	root = n;
}

template <typename E>
TNode<E> & Tree<E>::getRoot() {
	return root;
}

template <typename E>
TNode<E> & Tree<E>::addNode(TNode<E> &p, const E &e) {
	TNode<E> *n = new TNode<E>(e);

	if(isEmpty()) {
		setRoot(*n);
		size++;
		return root;
	}
	
	p.addChild(*n);
	n->setParent(p);
	
	size++;
	
	return *n;	
}

template <typename E>
bool Tree<E>::isEmpty() const {
	return size == 0;
}

template <typename E>
const int Tree<E>::depth(TNode<E> &n) const {
	if(n.isRoot()) {
		return 0;
	}

	return 1+depth(n.getParent());
}


template <typename E>
const int Tree<E>::height(TNode<E> &n) const {
	if(n.isExternal()) {
		return 0;
	}

	int maxHeight = 0;
	for(int i = 0; i < n.getChildren().size(); i++) {
		maxHeight = max(maxHeight, height(n.getChild(i))); 	
	}
	
	return 1 + maxHeight;
}

template <typename E>
void Tree<E>::preorderprint(const int i, TNode<E> &n) const {
	//print root
	for(int j = 0; j < i; j++) {
		cout << "    ";
	}
	
	cout << "Element: " << n.getElement();
	cout << " h: " << height(n) << " d: " << depth(n);
	cout << endl;
	//call preorderprint for each child
	for(int j = 0; j < n.getChildren().size(); j++) {
		preorderprint(i+1, n.getChild(j));
	}
}

template <typename E>
void Tree<E>::postorderprint(const int i, TNode<E> &n) const {
	//print children
	for(int j = 0; j < n.getChildren().size(); j++) {
		postorderprint(i+1, n.getChild(j));
	}	
	//print element
	
	for(int j = 0; j < i; j++) {
		cout << "    ";
	}

	cout << "Element: " << n.getElement();
	cout << " H: " << height(n) << " D: " << depth(n);
	cout << endl;
}

template <typename E>
void Tree<E>::breadthfirstprint() const {
	//use queue
	Queue<TNode<E> > q;
	q.enqueue(root);

	while (!q.isEmpty()) {
		TNode<E> n = q.front();
		cout << "Depth: " << depth(n) << " " << n << endl;
		q.dequeue();
	
		for(int i = 0; i < n.getChildren().size(); i++) {
			q.enqueue(n.getChild(i));
		}
	}
}


int main() {
	Tree<string> t;
	
	t.addNode(t.getRoot(), "/");

	cout << "root at beginning is " << t.getRoot().getElement() << endl;
	
	TNode<string> &usr = t.addNode(t.getRoot(), "usr");
	TNode<string> &home = t.addNode(t.getRoot(), "home");
	TNode<string> &dev = t.addNode(t.getRoot(), "dev");
	TNode<string> &david = t.addNode(home, "david");
	TNode<string> &bin = t.addNode(t.getRoot(), "bin");
	
	cout << t.getRoot().getElement() << endl;

	
	for(int i = 0; i < t.getRoot().getChildren().size(); i++) {
		cout << "    " << t.getRoot().getChild(i).getElement() << endl;
	}
	
	cout << t.getRoot().getChild(1).getChild(0).getElement() << endl;
	int d = t.depth(david);
	
	cout << "depth of d is " << d << endl;
	
	int h = t.height(t.getRoot());
	
	cout << "height of root is " << h << endl;

	cout << "\nPreorder Traversal:\n";	
	t.preorderprint(0, t.getRoot());
	
	cout << "\nPostorder Traversal:\n";
	t.postorderprint(0, t.getRoot());
	
	cout << "Breadth First Traversal:\n";
	t.breadthfirstprint();
}
