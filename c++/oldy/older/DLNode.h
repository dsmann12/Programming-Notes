#ifndef DLNODE_H
#define DLNODE_H

#include "Node.h"

template <typename E>
class DLNode : public Node<E> {
	public:
		DLNode();
		DLNode(const E &e);
		DLNode<E> * prev();
		DLNode<E> * next();
		void setPrev(DLNode<E> *n);
		void setNext(DLNode<E> *n);
	protected:
		DLNode<E> *_prev;
		DLNode<E> *_next;
};

template <typename E>
DLNode<E>::DLNode() :
	Node<E>::Node(), _prev(0), _next(0) {}

template <typename E>
DLNode<E>::DLNode(const E &e) :
	Node<E>::Node(e), _prev(0), _next(0) {}

template <typename E>
DLNode<E> * DLNode<E>::prev() {
	return _prev;
}

template <typename E>
DLNode<E> * DLNode<E>::next() {
	return _next;
}	

template <typename E>
void DLNode<E>::setPrev(DLNode<E> *n) {
	_prev = n;
}

template <typename E>
void DLNode<E>::setNext(DLNode<E> *n) {
	_next = n;
}

#endif
