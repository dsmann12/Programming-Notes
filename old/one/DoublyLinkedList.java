//Class Node
//String name
//Node next
//next

//Singly linked list
//Node head
//Node tail
//int size
public class DoublyLinkedList {
	DLNode header;
	DLNode trailer;
	int size;

	public DoublyLinkedList() {
		header = new DLNode();
		trailer = new DLNode();
		header.setNext(trailer);
		trailer.setPrev(header);
		size = 0;
	}

	public void addLast(DLNode n) {
		DLNode last = (DLNode) trailer.getPrev();
		trailer.setPrev(n);
		n.setPrev(last);
		last.setNext(n);
		n.setNext(trailer);
		size++;
	} 

	public DLNode removeLast() {
		DLNode last = (DLNode) trailer.getPrev();
		DLNode newLast = (DLNode) last.getPrev();
		newLast.setNext(trailer);
		trailer.setPrev(newLast);	
		size--;
		return last;	
	}

	//if list is empty then tail also is head
	public void addFirst(DLNode n) {
		DLNode first = (DLNode) header.getNext();
		first.setPrev(n);
		n.setNext(first);
		n.setPrev(header);
		header.setNext(n);
		size++;
	}

	public DLNode removeHead() {
		DLNode first = (DLNode) header.getNext();
		DLNode newFirst = (DLNode) first.getNext();
		header.setNext(newFirst);
		newFirst.setPrev(header);
		//first.setNext(null);
		//first.setPrev(null);
		size--;
		return first;
	}
		

	public void printList() {
		DLNode n = (DLNode) header.getNext();
		while(n.getNext() != null) {
			System.out.println(n.getName());
			n = (DLNode) n.getNext();
		}
	}

	public boolean isEmpty() {
		if(size == 0) {
			return true;
		}

		return false;
	}
	
	public static void main(String args[]) {
		DoublyLinkedList sl = new DoublyLinkedList();
		String s1 = "David";
		String s2 = "Emily";
		String s3 = "Ashleigh";
		String s4 = "Martina";
		String s5 = "Bradley";
		String names[] = {s1, s2, s3, s4, s5};
		for(String s : names) {
			DLNode n = new DLNode(s);
			sl.addLast(n);
		//	sl.printList();
		}
		System.out.println();

		sl.printList();
		
		SinglyLinkedList rsl = new SinglyLinkedList();

		for(String s : names) {
			DLNode n = new DLNode(s); 
			System.out.println("Adding..." + s);
			rsl.addFirst(n);
		}

		rsl.printList();
	}

}
		
