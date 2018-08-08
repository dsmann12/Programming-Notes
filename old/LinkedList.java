public class LinkedList {
	LNode head = null;
	LNode tail = null;
	int size;

	public LinkedList() {
		this.size = 0;
	}

	public void addFirst(LNode n) {
		n.setNext(head);
		head = n;
		if (this.isEmpty()) {
			tail = head;
		}
		size++;
	}

	public void  addLast(LNode n) {
		if(isEmpty()) {
			addFirst(n);
			return;
		}

		
	}

	public LNode getHead() {
		return head;
	}

	public LNode getTail() {
		return tail;
	}

	public LNode removeHead() {
		return head;
	}

	public int size() {
		return this.size;
	}

	public Boolean isEmpty() {
		return (this.size == 0);
	}

	public void printList() {
		LNode n = head;
		while(n != null) {
			System.out.println(n.getElement());
			n = n.getNext();
		}
	}

	public static void main(String args[]) {
		LNode<String> s1 = new LNode<String>("David");
		LNode<String> s2 = new LNode<String>("Emily");
		LNode<String> s3 = new LNode<String>("Ashleigh");
		LNode<String> s4 = new LNode<String>("Bradley");
		LNode<String> s5 = new LNode<String>("Martina");

		LinkedList ll = new LinkedList();
		ll.addFirst(s1);
		ll.addFirst(s2);
		ll.addFirst(s3);
		ll.addFirst(s4);
		ll.addFirst(s5);
		
		ll.printList();		
	}
}
