public class DLNode extends Node {
	protected Node prev;

	public DLNode() {
		name = null;
		next = null;
		prev = null;
	}

	public DLNode(String s) {
		name = s;
		next = null;
		prev = null;
	}

	public Node getPrev() {
		return this.prev;
	}

	public void setPrev(Node n) {
		this.prev = n;
	}
}
