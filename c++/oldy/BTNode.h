#ifndef BTNODE_H
#define BTNODE_H

#include "Node.h"

template <typename E>
class BTNode : public Node<E> {
	public:
		BTNode();
		BTNode(const E &e);
		~BTNode();
		BTNode<E> * left();
		BTNode<E> * right();
		BTNode<E> * parent();
		void setLeft(BTNode<E> * n);
		void setRight(BTNode<E> * n);
		void setParent(BTNode<E> *n);
		const int depth() const;
		const int height() const;
		void setDepth(const int d);
		void setHeight(const int h);
		bool hasLeft() const;
		bool hasRight() const;
		bool isExternal() const;
		bool isInternal() const;
		bool isRoot() const;
		bool isBalanced() const;
	protected:
		BTNode<E> * _parent;
		BTNode<E> * _left;
		BTNode<E> * _right;
		int _depth, _height;
};

template <typename E>
BTNode<E>::BTNode() :
	Node<E>::Node(), _depth(0), _height(0),
	_parent(0), _left(0), _right(0) {}

template <typename E>
BTNode<E>::BTNode(const E &e) :
	Node<E>::Node(e), _depth(0), _height(0),
	_parent(0), _left(0), _right(0) {}

template <typename E>
BTNode<E>::~BTNode() {
	delete _left;
	delete _right;
}

template <typename E>
BTNode<E> * BTNode<E>::left() {
	return _left;
}

template <typename E>
BTNode<E> * BTNode<E>::right() {
	return _right;
}

template <typename E>
BTNode<E> * BTNode<E>::parent() {
	return _parent;
}

template <typename E>
void BTNode<E>::setLeft(BTNode<E> * n) {
	_left = n;
	n->setParent(this);
}

template <typename E>
void BTNode<E>::setRight(BTNode<E> *n) {
	_right = n;
	n->setParent(this);
}

template <typename E>
void BTNode<E>::setParent(BTNode<E> *n) {
	_parent = n;
}

template <typename E>
const int BTNode<E>::depth() const {
	return _depth;
}

template <typename E>
const int BTNode<E>::height() const {
	return _height;
}

template <typename E>
void BTNode<E>::setDepth(const int d) {
	_depth = d;
}

template <typename E>
void BTNode<E>::setHeight(const int h) {
	_height = h;
}

template <typename E>
bool BTNode<E>::hasLeft() const {
	return (_left != 0);
}
template <typename E>
bool BTNode<E>::hasRight() const {
	return (_right != 0);
}

template <typename E>
bool BTNode<E>::isExternal() const {
	return (!hasRight() && !hasLeft());
}

template <typename E>
bool BTNode<E>::isInternal() const {
	return (!isExternal());
}

template <typename E>
bool BTNode<E>::isRoot() const {
	return (_parent == 0);
}

template <typename E>
bool BTNode<E>::isBalanced() const {
	int x = std::abs((left()->height()) - (right()->height()));
	return (x <= 1);
}

#endif

