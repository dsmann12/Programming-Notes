#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "DoublyLinkedList.h"

using namespace std;

int main() {
	DoublyLinkedList<string> dl;
	dl.addFirst("David");
	dl.addLast("Emily");
	dl.addLast("Bradley");
	dl.addLast("Ashleigh");
	dl.addLast("Martina");
	
	dl.printList();
	
	cout << endl;
	
	dl.printLast();
	dl.printFirst();

	dl.removeLast();
	dl.removeLast();
	dl.addFirst("Martina");
	
	cout << endl;
	
	dl.printList();
	
	dl.removeLast();
	dl.removeFirst();
	
	cout << endl;
	
	dl.printList();
	
	cout << endl; 
	dl.printFirst();
	dl.printLast();

	dl.removeLast();
	
	cout << endl;
	
	dl.printFirst();
	dl.printLast();	
	
	dl.removeLast();
	dl.removeFirst();

	dl.removeLast();
	dl.removeFirst();
	
	cout << "\nPrinting first and last\n";

	dl.printFirst();
	dl.printLast();	
}
