#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template <typename E>
class Queue : public LinkedList<E> {
	public:
		Queue();
		~Queue();
		void enqueue(const E &e);
		void dequeue();	
}; 

template <typename E>
Queue<E>::Queue() :
	LinkedList<E>::LinkedList() {}


template <typename E>
Queue<E>::~Queue() {}

template <typename E>
void Queue<E>::enqueue(const E &e) {
	this->addLast(e);
}

template <typename E>
void Queue<E>::dequeue() {
	this->removeFront();
}

#endif
