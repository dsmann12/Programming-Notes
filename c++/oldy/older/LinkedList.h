#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LNode.h"

template <typename E>
class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		//addfront
		void addFront(const E &e);
		//addLast
		void addLast(const E &e);
		void removeFront();
		//front
		const E & front() const;
		//last
		const E & last() const;
		//empty
		bool empty() const;
		//size	
		const int size() const;
		void print() const;
	protected:
		LNode<E> *head, *tail;
		int _size;
};

template <typename E>
LinkedList<E>::LinkedList() :
	head(0), tail(0), _size(0) {}

template <typename E>
LinkedList<E>::~LinkedList() {
	while(!empty()) {
		removeFront(); 
	}
}

template <typename E>
void LinkedList<E>::addFront(const E &e) {
	LNode<E> *n = new LNode<E>(e);
	
	if(empty()) {
		head = n;
		tail = head;
	}
	else {
		LNode<E> *old = head;
		n->setNext(old);
		head = n;
	}
	_size++;
}

template <typename E>
void LinkedList<E>::addLast(const E &e) {
	if(empty()) {
		addFront(e);
		return;
	}

	LNode<E> *n = new LNode<E>(e);
	tail->setNext(n);
	tail = n;		
	_size++;
}

template <typename E>
void LinkedList<E>::removeFront() {
	if(empty()) {
		std::cerr << "List is empty!\n";
		return;
	}
		
	LNode<E> *old = head;
	head = head->next();
	delete old;
	_size--;
}

template <typename E>
const E & LinkedList<E>::front() const {
	if(empty()) {
		throw std::exception();
	}

	return head->getElement();
}

template <typename E>
const E & LinkedList<E>::last() const {
	if(empty()) {
		throw std::exception();
	}

	return tail->getElement();
}

template <typename E>
const int LinkedList<E>::size() const {
	return _size;
}

template <typename E>
bool LinkedList<E>::empty() const {
	return (_size == 0);
}

template <typename E>
void LinkedList<E>::print() const {
	if(empty()) {
		std::cerr << "List is empty!\n";
		return;
	}
		
	LNode<E> *n = head;
	while(n != 0) {
		std::cout << *n << std::endl;
		n = n->next();
	}
}

#endif
