public class Node {
	protected String name;
	protected Node next;

	public Node() {
		name = null;
		next = null;
	}
	
	public Node(String s) {
		name = s;
		next = null;
	}

	public Node getNext() {
		return this.next;
	}

	public String getName() {
		return this.name;
	}

	public void setNext(Node n) {
		this.next = n;
	}

	public void setName(String s) {
		this.name = s;
	}
}
	
