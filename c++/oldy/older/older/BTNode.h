#ifndef BTNODE_H
#define BTNODE_H

#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;

template <typename E>
class BTNode : public Node<E> {
	public:
		BTNode();
		BTNode(const E &e);
		~BTNode();
		class BTNodeException {};
		void setLeft(BTNode<E> &n);
		BTNode<E> & getLeft();
		void setRight(BTNode<E> &n);
		BTNode<E> & getRight();
		void setParent(BTNode<E> &n);
		BTNode<E> & getParent();
		bool hasLeft() const;
		bool hasRight() const;
		void setIndex(const int i);
		const int getIndex() const;
		void setDepth(const int d);
		const int getDepth() const;
		void setHeight(const int h);
		const int getHeight() const;
		bool isExternal() const;
		bool isInternal() const;
		bool isRoot() const;		
		
	private:
		BTNode<E> *parent, *left, *right;
		int index, height, depth;
};

template <typename E>
BTNode<E>::BTNode() {
	parent = left = right = 0;
	index = height = depth = 0;
}

template <typename E>
BTNode<E>::BTNode(const E &e) {
	this->element = e;
}

template <typename E>
BTNode<E>::~BTNode() {}

template <typename E>
void BTNode<E>::setLeft(BTNode<E> &n) {
	left = &n;
	n.setParent(*this);
	n.setIndex((2*index) + 1);
}

template <typename E>
BTNode<E> & BTNode<E>::getLeft() {
	if(left == 0) {
		throw BTNodeException();		
	}

	return *left;
}

template <typename E>
void BTNode<E>::setRight(BTNode<E> &n) {
	right = &n;
	n.setParent(*this);
	n.setIndex((2*index) + 2);
}

template <typename E>
BTNode<E> & BTNode<E>::getRight() {
	if(right == 0) {
		throw BTNodeException();
	}

	return *right;
}

template <typename E>
void BTNode<E>::setParent(BTNode<E> &n) {
	parent = &n;
}

template <typename E>
BTNode<E> & BTNode<E>::getParent() {
	if(parent == 0) {
		throw BTNodeException();
	}
	
	return *parent;
}

template <typename E>
bool BTNode<E>::hasLeft() const {
	return left != 0;
}

template <typename E>
bool BTNode<E>::hasRight() const {
	return right != 0;
}

template <typename E>
void BTNode<E>::setIndex(const int i) {
	index = i;
}

template <typename E>
const int BTNode<E>::getIndex() const {
	return index;
}

template <typename E>
void BTNode<E>::setDepth(const int d) {
	depth = d;
}

template <typename E>
const int BTNode<E>::getDepth() const {
	return depth;
}

template <typename E>
void BTNode<E>::setHeight(const int h) {
	height = h;
}

template <typename E>
const int BTNode<E>::getHeight() const {
	return height;
}

template <typename E>
bool BTNode<E>::isExternal() const {
	return (!hasLeft() && !hasRight());
}

template <typename E>
bool BTNode<E>::isInternal() const {
	return (hasLeft() || hasRight());
}

template <typename E>
bool BTNode<E>::isRoot() const {
	return (parent == 0);
}




#endif
