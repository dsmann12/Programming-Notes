public class LNode <E> extends Node <E> {
	protected LNode next;

	public LNode() {
		this.next = null;
		this.element = null;
	}

	public LNode(E element, LNode n) {
		this.element = element;
		this.next = n;
	}

	public LNode(E element) {
		this.element = element;
		this.next = null;
	}

	public LNode getNext() {
		return this.next;
	}
	
	public void  setNext(LNode n) {
		this.next = n;
	}
}
