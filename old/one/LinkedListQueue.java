public class LinkedListQueue extends SinglyLinkedList {
	//head
	//node tali
	//int size

	public LinkedListQueue() {
		size = 0;
	}

	public void enqueue(String s) {
		Node n = new Node(s);
		addLast(n);
	}

	public String dequeue() {
		String s = head.getName();
		removeHead();
		return s;
	}

	public String front() {
		String s = head.getName();
		return s;
	}

	public int size() {
		return size;
	}

	public static void main(String args[]) {
		LinkedListQueue q = new LinkedListQueue();
		
		q.enqueue("David");
		q.enqueue("Emily");
		q.enqueue("Ashleigh");
		q.enqueue("Martina");
		q.enqueue("Bradley");

		while(!q.isEmpty()) {
			System.out.println(q.dequeue());
		}
	}
}
	
