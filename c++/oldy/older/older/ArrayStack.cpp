#include <iostream>
#include <cstdlib>

using namespace std;


template <typename E>
class ArrayStack {
	public:
		ArrayStack();
		~ArrayStack();
		class StackException {};
		void push(const E &e);
		void pop();
		E & top() const;
		bool isEmpty() const;
		bool isFull() const;
		int getSize() const;
		void printTop() const;
		void printStack() const;
		void clearStack();
	private:
		const int DEFAULTMAX = 10;
		int max;
		int size;	
		E *stack;
};

template <typename E>
ArrayStack<E>::ArrayStack() {
	max = DEFAULTMAX;
	stack = new E[max];
	size = 0;
}

template <typename E>
ArrayStack<E>::~ArrayStack() {
	delete[] stack;
}

template <typename E>
void ArrayStack<E>::push(const E &e) {
	try {
		if(isFull()) {
			throw StackException();
		}
	
		stack[size++] = e;
	}
	catch(StackException) {
		cout << "Stack if full!\n";
	}
}

template <typename E>
void ArrayStack<E>::pop() {
	try {
		if(isEmpty()) {
			throw StackException();
		}
		
		size--;
	}
	catch(StackException) {
		cout << "Stack is empty!\n";
	}	
}

template <typename E>
E & ArrayStack<E>::top() const {
	if(isEmpty()) {
		throw StackException();
	}
	
	return stack[size-1];
}

template <typename E>
bool ArrayStack<E>::isFull() const {
	return (size == max);
}

template <typename E> 
bool ArrayStack<E>::isEmpty() const {
	return (size == 0);
}

template <typename E>
void ArrayStack<E>::printTop() const {
	try {
		cout << top() << endl;
	}
	catch(StackException) {
		cout << "Stack is empty!\n";
	}
}

template <typename E>
void ArrayStack<E>::printStack() const {
	cout << "\nPrinting stack!\n";
	for(int i = size-1; i >= 0; i--) {
		cout << stack[i] << endl;
	}
}

template <typename E>
void ArrayStack<E>::clearStack() {
	cout << "\nClearing stack!\n";
	while(!isEmpty()) {
		printTop();
		pop();
	}
}

int main() {
	ArrayStack<string> s;
	s.push("David");
	s.printTop();
	s.printStack();

	s.push("Emily");
	s.push("Bradley");
	s.push("This is the top, bitches");
	
	s.printStack();	
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	
	s.push("Bradley");
	s.push("Martina");
	s.push("Ashleigh");
	s.push("Emily");
	s.push("David");
	
	s.printStack();
	s.clearStack();
}
