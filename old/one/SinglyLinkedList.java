//Class Node
//String name
//Node next
//next

//Singly linked list
//Node head
//Node tail
//int size
public class SinglyLinkedList {
	protected Node head;
	protected Node tail;
	protected int size;

	public SinglyLinkedList() {
		size = 0;
	}

	public void addLast(Node n) {
		if(this.isEmpty()) {
			this.addFirst(n);
			return;
		}
		tail.setNext(n);
		tail = n;
		n.setNext(null);
		size++;
	} 

	public void removeLast() {
		
	} // really bad

	//if list is empty then tail also is head
	public void addFirst(Node n) {
		n.setNext(head);
		head = n;
		if(this.isEmpty()) {
			tail = head;
		}
		size++;
	}

	public void removeHead() {
		Node n = head;
		head = head.getNext();
		n.setNext(null);
		size--;
	}
		

	public void printList() {
		Node n = head;
		while(n != null) {
			System.out.println(n.getName());
			n = n.getNext();
		}
	}

	public boolean isEmpty() {
		if(size == 0) {
			return true;
		}

		return false;
	}
	
	public static void main(String args[]) {
		SinglyLinkedList sl = new SinglyLinkedList();
		String s1 = "David";
		String s2 = "Emily";
		String s3 = "Ashleigh";
		String s4 = "Martina";
		String s5 = "Bradley";
		String names[] = {s1, s2, s3, s4, s5};
		for(String s : names) {
			Node n = new Node(s);
			sl.addLast(n);
		//	sl.printList();
		}
		System.out.println();

		sl.printList();
		
		SinglyLinkedList rsl = new SinglyLinkedList();

		for(String s : names) {
			Node n = new Node(s);
			System.out.println("Adding..." + s);
			rsl.addFirst(n);
		}

		rsl.printList();
	}

}
		
