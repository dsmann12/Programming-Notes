#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<string> ll;
	ll.addFirst("David");
	
	ll.printFirst();
	ll.printFirst();

	ll.addFirst("Emily");
	ll.addFirst("Bradley");
	ll.addFirst("Ashleigh");

	ll.printList();

	ll.removeFirst();
	
	cout << endl;
	
	ll.printList();

	ll.removeFirst();
	ll.removeFirst();
	ll.removeFirst();

	ll.printList();

	ll.printList();

	ll.removeFirst();
	
	ll.removeFirst();
	
	ll.addLast("David");
	ll.printList();
	ll.addLast("Bradley");
	ll.addLast("Emily");
	
	ll.printLast();
	
	ll.printList();
}
