#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

template <typename E>
class Stack : public LinkedList<E> {
	public:
		Stack();
		~Stack();
		void push(const E &e);
		void pop();
		E top() const;
		void clearStack();
		void printStack() const;
		void printTop() const;
};

template <typename E>
Stack<E>::Stack() :
	LinkedList<E>()
{}

template <typename E>
Stack<E>::~Stack() {

}

template <typename E>
void Stack<E>::push(const E &e) {
	this->addFirst(e);
}

template <typename E>
void Stack<E>::pop() {
	this->removeFirst();
}

template <typename E>
E Stack<E>::top() const {
	return this->first();
}
	
template <typename E>
void Stack<E>::printStack() const {
	this->printList();
}

template <typename E>
void Stack<E>::printTop() const {
	this->printFirst();
}

template <typename E>
void Stack<E>::clearStack() {
	cout << "\nClearing Stack!\n";
	while(!this->isEmpty()) {
		this->printFirst();
		pop();
	}
}

int main() {
	Stack<string> s;
	s.push("Bradley");
	s.push("Martina");
	s.push("Ashleigh");
	s.push("Emily");
	s.push("David");
	
	s.printStack();
	
	cout << endl;
	s.printTop();
	cout << endl;
	
	s.pop();
	
	s.printStack();
	
	s.pop();
	
	cout << "\ntop is ";
	s.printTop();
	
	s.pop();
	cout << endl;
	
	s.printStack();
	
	s.pop();
	
	cout << "Stack is\n";
	s.printStack();
	cout << "\nTop is\n";
	s.printTop();
	
	s.pop();
	s.pop();
	s.pop();
	
	s.printTop();
	s.printStack();
	
}
