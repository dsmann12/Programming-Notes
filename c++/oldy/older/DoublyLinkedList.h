#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "DLNode.h"

template <typename E>
class DoublyLinkedList {
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		//addFront
		void addFront(const E &e);
		//addLast
		void addLast(const E &e);
		//addBefore
		void addBefore(DLNode<E> &n, const E &e);
		//addAfter
		void addAfter(DLNode<E> &n, const E &e);
		//removeFront
		void removeFront();
		//removeLast
		void removeLast();
		//removeBefore()
		void removeBefore(DLNode<E> &n);
		//removeAfter()
		void removeAfter(DLNode<E> &n);
		//front()
		const E & front() const;
		//last()
		const E & last() const;
		//empty()
		bool empty() const;
		//size()
		const int size() const;
		void print() const;
	protected:
		DLNode<E> *header, *trailer;
		int _size;
};

template <typename E>
DoublyLinkedList<E>::DoublyLinkedList() :
	_size(0) 
{
	header = new DLNode<E>();
	trailer = new DLNode<E>();
	header->setNext(trailer);
	trailer->setPrev(header);
}

template <typename E>
DoublyLinkedList<E>::~DoublyLinkedList() {
	while(!empty()) {
		removeFront();
	}
	delete header;
	delete trailer;
}

template <typename E>
void DoublyLinkedList<E>::addFront(const E &e) {
	DLNode<E> *n = new DLNode<E>(e);

	//Add before old front
	DLNode<E> *oldFront = header->next();
	n->setNext(oldFront);
	oldFront->setPrev(n);

	//set new Front
	header->setNext(n);
	n->setPrev(header);

	_size++;
	
}

template <typename E>
void DoublyLinkedList<E>::addLast(const E &e) {
	DLNode<E> *n = new DLNode<E>(e);
	
	//add after old last
	DLNode<E> *oldLast = trailer->prev();
	n->setPrev(oldLast);
	oldLast->setNext(n);
	
	//set new last
	trailer->setPrev(n);
	n->setNext(trailer);
	
	_size++;
}

template <typename E>
void DoublyLinkedList<E>::addBefore(DLNode<E> &n, const E &e) {
	DLNode<E> *b = new DLNode<E>(e);

	//oldPrev
	DLNode<E> *oldPrev = n.prev();
	
	//set b
	b->setNext(n);
	b->setPrev(oldPrev);

	//set old
	n->setPrev(b);	
	oldPrev->setNext(b);
	
	_size++;
}

template <typename E>
void DoublyLinkedList<E>::addAfter(DLNode<E> &n, const E &e) {
	DLNode<E> *a = new DLNode<E>(e);
	
	//oldNext
	DLNode<E> *oldNext = n->next();
	
	//set a
	a->setPrev(n);
	a->setNext(oldNext);

	//set old
	n->setNext(a);
	oldNext->setPrev(a);

	_size++;
}

template <typename E>
void DoublyLinkedList<E>::removeFront() {
	DLNode<E> *f = header->next();
	DLNode<E> *head = f->next();
	
	header->setNext(head);
	head->setPrev(header);
	
	delete f;
	
	_size--;
}

template <typename E>
void DoublyLinkedList<E>::removeLast() {
	DLNode<E> *l = trailer->prev();
	DLNode<E> *last = l->prev();
	
	trailer->setPrev(last);
	last->setNext(trailer);

	delete l;
	
	_size--;
}
	
template <typename E>
void DoublyLinkedList<E>::removeBefore(DLNode<E> &n) {
	DLNode<E> *b = n->prev();
	DLNode<E> *before = b->prev();
	
	before->setNext(n);
	n->setPrev(before);
	
	delete b;
	
	_size--;
}
template <typename E>
void DoublyLinkedList<E>::removeAfter(DLNode<E> &n) {
	DLNode<E> *a = n->next();
	DLNode<E> *after = a->next();
	
	after->setPrev(n);
	n->setNext(after);
	
	delete a;

	_size--;	
}

template <typename E>
const E & DoublyLinkedList<E>::front() const {
	if(empty()) {
		throw std::exception();
	}
	
	return header->next()->getElement();
}

template <typename E>
const E & DoublyLinkedList<E>::last() const {
	if(empty()) {
		throw std::exception();
	}
	
	return trailer->prev()->getElement();
}

template <typename E>
const int DoublyLinkedList<E>::size() const {
	return _size;
}

template <typename E>
bool DoublyLinkedList<E>::empty() const {
	return (_size == 0);
}

template <typename E>
void DoublyLinkedList<E>::print() const {
	if(empty()) {
		std::cout << "List is empty!\n";
		return;
	}
	
	DLNode<E> *n = header->next();
	
	while(n->next() != 0) {
		std::cout << n->getElement() << std::endl;
		n = n->next();
	}
}
#endif
