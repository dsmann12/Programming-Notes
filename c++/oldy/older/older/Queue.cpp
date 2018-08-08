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
		E & front();
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
E & Queue<E>::front() {
	return this->first();
}

int main() {
	Queue<string> q;
	q.enqueue("David");
	q.enqueue("Emily");
	q.enqueue("Bradley");
	
	q.printList();
	
	cout << endl;
	
	q.printFirst();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();		
}
