#include <iostream>
#include <cstdlib>
#include "Queue.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	Queue<string> q;
	q.enqueue("David");
	q.enqueue("Emily");
	q.enqueue("Bradley");
	q.enqueue("Ashleigh");
	q.enqueue("Martina");
	
	q.print();
	
	cout << "First is: " << q.front() << endl;
	cout << "Last is " << q.last() << endl;
	
	q.dequeue();
	
	cout << endl << "Now first is " << q.front() << endl;
	cout << "Last is still " << q.last() << endl;
	
	q.print();
	
	q.dequeue();
	q.dequeue();
	q.dequeue();
	
	cout << endl;	
	q.print();
	
	q.enqueue("David");
	
	cout << endl;
	
	q.print();
	
	q.dequeue();
	q.dequeue();
	q.dequeue();
}
