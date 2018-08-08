#ifndef LNODE_H
#define LNODE_H

#include "Node.h"

template <typename E>
class LNode : public Node<E> {
	public:
		LNode();
		LNode(const E &e);
		LNode<E> * next();
		void setNext(LNode<E> *n);
	protected:
		LNode<E> *_next;
};

template <typename E>
LNode<E>::LNode() :
	Node<E>::Node(), _next(0) {}

template <typename E>
LNode<E>::LNode(const E &e) :
	Node<E>::Node(e), _next(0) {}

template <typename E>
LNode<E> * LNode<E>::next() {
	return _next;
}

template <typename E>
void LNode<E>::setNext(LNode<E> *n) {
	_next = n;
}

#endif

