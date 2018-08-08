#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;

template <typename E>
class DoublyLinkedList {
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		class LinkedListException {};
		void addFirst(const E &e);
		void removeFirst();
		E first() const;
		void addLast(const E &e);
		void removeLast();
		E last() const;
		bool isEmpty() const;
		int getSize() const;
		void printList() const;
		void printFirst() const;
		void printLast() const;
	private:
		DLNode<E> *header;
		DLNode<E> *trailer;
		int size;
};

template <typename E>
DoublyLinkedList<E>::DoublyLinkedList() {
	header = new DLNode<E>();
	trailer = new DLNode<E>();

	header->setNext(trailer);
	trailer->setPrev(header);
		
	size = 0;
}

template <typename E>
DoublyLinkedList<E>::~DoublyLinkedList() {
	while(!isEmpty()) {
		removeLast();
	}
	
	delete header;
	delete trailer;
}

template <typename E>
void DoublyLinkedList<E>::addFirst(const E &e) {
	DLNode<E> *old = header->getNext();
	DLNode<E> *first = new DLNode<E>(e);
	
	header->setNext(first);
	first->setPrev(header);
	
	first->setNext(old);
	old->setPrev(first);
	
	size++;
}

template <typename E>
void DoublyLinkedList<E>::removeFirst() {
	try {
		if(isEmpty()) {
			throw LinkedListException();
		}
		DLNode<E> *old = header->getNext();
		DLNode<E> *first = old->getNext();
	
		header->setNext(first);
		first->setPrev(header);
		
		size--;
	
		delete old;
	}
	catch(LinkedListException) {
		cout << "List is empty!\n";
	}		
}

template <typename E>
E DoublyLinkedList<E>::first() const {
	if(isEmpty()) {
		throw LinkedListException();
	}

	DLNode<E> *n = header->getNext();
	return n->getElement();

}

template <typename E>
void DoublyLinkedList<E>::addLast(const E &e) {
	DLNode<E> *old = trailer->getPrev();
	DLNode<E> *last = new DLNode<E>(e);
	
	trailer->setPrev(last);
	last->setNext(trailer);

	last->setPrev(old);
	old->setNext(last);
	
	size++;
}

template <typename E>
void DoublyLinkedList<E>::removeLast() {
	try {
		if(isEmpty()) {
			throw LinkedListException();
		}
	
		DLNode<E> *old = trailer->getPrev();
		DLNode<E> *last = old->getPrev();

		trailer->setPrev(last);
		last->setNext(trailer);
		
		size--;
		
		delete old;
	}
	catch(LinkedListException) {
		cout << "List is empty!\n";
	}
}

template <typename E>
E DoublyLinkedList<E>::last() const {
	if(isEmpty()) {
		throw LinkedListException();
	}
	
	DLNode<E> *n = trailer->getPrev();
	return n->getElement();
}

template <typename E>
bool DoublyLinkedList<E>::isEmpty() const {
	return (size == 0);
}

template <typename E>
int DoublyLinkedList<E>::getSize() const {
	return size;
}

template <typename E>
void DoublyLinkedList<E>::printList() const {
	DLNode<E> *n = header->getNext();
	
	while(n->getNext() != NULL) {
		cout << n->getElement() << endl;
		n = n->getNext();
	}
}

template <typename E>
void DoublyLinkedList<E>::printFirst() const {
	try {
		if(isEmpty()) {
			throw LinkedListException();
		}

		cout << first() << endl;
	}
	catch(LinkedListException) {
		cout << "List is empty!\n";
	}
}

template <typename E>
void DoublyLinkedList<E>::printLast() const {
	try {
		if(isEmpty()) {
			throw LinkedListException();
		}
		
		cout << last() << endl;
	}
	catch(LinkedListException) {
		cout << "List is empty!\n";
	}
}


#endif
