public class LinkedListStack extends SinglyLinkedList{
	
	public LinkedListStack() {

	}

	public void push(String s) {
		Node n = new Node(s);
		addFirst(n);
	}

	public String pop() {
		if(this.isEmpty()) {
			System.out.println("Empty!");
			return null;
		}
		String s = head.getName();
		removeHead();
		return s;
	}

	public String top() {
		if(this.isEmpty()) {
			System.out.println("Empty!");
			return null;
		}
		return head.getName();
	}

	public int size() {
		return this.size;
	}

	public static void main(String args[]) {
		LinkedListStack s = new LinkedListStack();
		s.push("David");
		s.push("Emily");
		s.push("Ashleigh");
		s.push("Martina");
		s.push("Bradley");

		System.out.println("Size is: " + s.size());

		while(!s.isEmpty()) {
			System.out.println(s.pop());
		}
	}		
	
}
