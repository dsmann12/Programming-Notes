#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include "TNode.h"
#include "Queue.h"

template <typename E>
class Tree {
	public:
		Tree();
		~Tree();
		void addNode(const E &e);
		void addNode(TNode<E> &p, const E &e);
		void removeNode(TNode<E> &n);
		TNode<E> & root();
		void setRoot(const TNode<E> &n);
		const int depth(TNode<E> &n) const;
		const int height(TNode<E> &n) const;
		void preorderprint(const int i, TNode<E> &n) const;
		void postorderprint(const int i, TNode<E> &n) const;
		void bfsprint() const;
		bool empty() const;
		const int size() const;
	protected:
		TNode<E> _root;
		int _size;
};


template <typename E>
Tree<E>::Tree() :
		_size(0) {}

template <typename E>
Tree<E>::~Tree() {}

template <typename E>
void Tree<E>::addNode(const E &e) {
	TNode<E> *n = new TNode<E>(e);
	
	if(empty()) {
		setRoot(*n);	
		_size++;
		return;
	}

	_root.addChild(*n);
	_size++;
}

template <typename E>
void Tree<E>::addNode(TNode<E> &p, const E &e) {
	TNode<E> *n = new TNode<E>(e);

	p.addChild(*n);
	_size++;
}

template <typename E>
void Tree<E>::removeNode(TNode<E> &n) {

}

template <typename E>
TNode<E> & Tree<E>::root() {
	return _root;
}

template <typename E>
void Tree<E>::setRoot(const TNode<E> &n) {
	_root = n;
}

template <typename E>
const int Tree<E>::depth(TNode<E> &n) const {
	//how many ancestors
	
	//if root, depth is 0
	if(n.isRoot()) {
			return 0;
	}

	return 1+depth(*n.parent());
}

template <typename E>
const int Tree<E>::height(TNode<E> &n) const {
	//if node is external it has height 0
	if(n.isExternal()) {
		return 0;
	}

	int h = 0;

	for(int i = 0; i < n.children().size(); i++) {
		h = std::max(h, height(*n.child(i)));
	}	

	return 1 + h;
}

template <typename E>
void Tree<E>::preorderprint(const int i, TNode<E> &n) const {
	//recursive
	//print node,
	//then recursively travel through children
	for(int j = 0; j < i; j++) {
			std::cout << "    ";
	}

	std::cout << "Level: " << i << " Node: " << n << std::endl;
	
	for(int c = 0; c < n.children().size() ; c++) {
		preorderprint(i+1, *n.child(c));
	}	
	
}

template <typename E>
void Tree<E>::postorderprint(const int i, TNode<E> &n) const {
	//print children so recursive calls
	//children must print before parent
	//
	
	for(int c = 0; c < n.children().size(); c++) {
		postorderprint(i+1, *n.child(c));
	}

	for(int j = 0; j < i; j++) {
		std::cout << "    ";
	}

	std::cout << "Level: " << i << " Node: " << n << std::endl;
}

template <typename E>
void Tree<E>::bfsprint() const {
	//For each level place a node in the queue
	//At end of each level print the queue
	//
	
	Queue<TNode<E> > q;
	q.enqueue(_root);

	while(!q.empty()) {
		TNode<E> n = q.front();
		q.dequeue();

		std::cout << n << std::endl;

		for(int i = 0; i < n.children().size(); i++) {
			q.enqueue(*n.child(i));
		}
	}
}

template <typename E>
bool Tree<E>::empty() const {
	return (_size == 0);
}

template <typename E>
const int Tree<E>::size() const {
	return _size;
}

#endif
