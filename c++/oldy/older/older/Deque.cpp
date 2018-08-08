#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "DoublyLinkedList.h"

int main() {
	DoublyLinkedList<string> dl;
	dl.printList();
	dl.addFirst("David");
	dl.addLast("Emily");
	dl.addLast("Bradley");
	
	cout << "Last is ";
	dl.printLast();
	
	cout << "First is ";
	dl.printFirst();
	
	cout << endl;
	
	cout << "List is: \n";
	dl.printList();
	
	dl.removeLast();
	dl.removeLast();
	
	cout << "\nList is: \n";
	dl.printList();
	
	dl.removeFirst();
	dl.removeFirst();
	dl.removeLast();
}
