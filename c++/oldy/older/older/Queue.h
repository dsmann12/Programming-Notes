#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

template <typename E>
class Queue : public LinkedList<E> {
	public:
		Queue();
		~Queue();
		void enqueue(const E &e);
		void dequeue();
		const E & front() const;
};

template <typename E>
Queue<E>::Queue()
{}

template <typename E>
Queue<E>::~Queue() {}

template <typename E>
void Queue<E>::enqueue(const E &e) {
	this->addLast(e);	
}

template <typename E>
void Queue<E>::dequeue() {
	try {
		this->removeFirst();
	}
	catch(...) {
		cout << "Queue is empty!\n";
	}
}

template <typename E>
const E & Queue<E>::front() const{
	return this->first();
}

#endif
