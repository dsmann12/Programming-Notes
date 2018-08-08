#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;

template <typename E>
class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		class LinkedListException {};
		const E & first() const; //doesn't modify
		void addFirst(const E &e); //modifiers
		void removeFirst(); //modifies
		const E & last() const;
		void addLast(const E &e);
		bool isEmpty() const;
		int getSize() const;
		void printList() const;
		void printFirst() const;
		void printLast() const;
	protected:
		LNode<E> *head, *tail;
		int size;
};

template <typename E>
LinkedList<E>::LinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

template <typename E>
LinkedList<E>::~LinkedList() {
	while(!isEmpty()) {
		removeFirst();
	}
}

template <typename E>
void LinkedList<E>::addFirst(const E &e) {
	LNode<E> *old = head;
	LNode<E> *first = new LNode<E>(e);
	first->setNext(old);
	head = first;	
	
	if(isEmpty()) {
		tail = head;
	}
	
	size++;
	
}

template <typename E>
const E & LinkedList<E>::first() const {
	if(isEmpty()) { 
		throw LinkedListException(); 
	}

	return head->getElement();
}

template <typename E>
void LinkedList<E>::removeFirst() {
	try {
		if(isEmpty()) {
			throw LinkedListException();
		}
	
		LNode<E> *old = head;
		head = old->getNext();
		size--;
		delete old;
	}	
	catch(LinkedListException) {
		cout << "List is empty!\n";
		return;
	}
}

template <typename E>
const E & LinkedList<E>::last() const {
	if(isEmpty()) {
		throw LinkedListException();
	}		
	
	return tail->getElement();
}

template <typename E>
void LinkedList<E>::addLast(const E &e) {
	if(isEmpty()) {
		addFirst(e);
		return;
	}
	
	LNode<E> *old = tail;
	LNode<E> *n = new LNode<E>(e);

	//old is tail. Pointer that points to last node
	//also points to first if 	
	old->setNext(n);
	tail = n;
	
	size++;
}

template <typename E>
bool LinkedList<E>::isEmpty() const { 
	return (size == 0);
} 

template <typename E>
int LinkedList<E>::getSize() const {
	return size;
}

template <typename E>
void LinkedList<E>::printList() const{
	LNode<E> *n = head;
	while(n != NULL) {
		cout << n->getElement() << endl;
		n = n->getNext();
	}
}

template <typename E>
void LinkedList<E>::printFirst() const {
	try {
		cout << first() << endl;
	}
	catch(LinkedListException) {
		cout << "List is empty!\n";
	}
}

template <typename E>
void LinkedList<E>::printLast() const {
	try {
		cout << last() << endl;
	}
	catch(LinkedListException) {
		cout << "Stack is empty!\n";
	}
}

#endif
