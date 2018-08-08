#include <iostream>
#include "DoublyLinkedList.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	DoublyLinkedList<string> dl;
	
	dl.addFront("David");
	
	cout << dl.front() << endl;
	
	dl.addLast("Emily");
	dl.addLast("Bradley");
	
	cout << dl.front() << endl;
	cout << dl.last() << endl;
	
	cout << endl;
	
	dl.print();
	
	dl.addFront("Martina");
	dl.addFront("Ashleigh");
	dl.addLast("Neej");
	
	cout << endl;
	
	dl.print();
	
	dl.removeFront();
	dl.removeFront();
	
	dl.addLast("Ashleigh");
	dl.addLast("Martina");
	
	cout << endl;
	
	dl.print();
	cout << dl.size() << endl;
}
