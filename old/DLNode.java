public class DLNode <E> extends Node <E> {
	protected DLNode prev;
	protected DLNode next;
	
	public DLNode() {
		this.element = null;
		this.next = null;
		this.prev = null;
	}

	public DLNode(E element) {
		this.element = element;
		this.next = null;
		this.prev = null;
	}

	public DLNode(E element, DLNode prev) {
		this.element = element;
		this.next = null;
		this.prev = prev;
	}

	public DLNode(E element, DLNode prev, DLNode next) {
		this.element = element;
		this.next = next;
		this.prev = prev;
	}
	
	//Override
	public DLNode getNext() {	
		return this.next;
	}

	public DLNode getPrev() {
		return this.prev;
	}

	public void setPrev(DLNode n) {
		this.prev = n;
	}

	public void setNext(DLNode n) {
		this.next = n;
	}
}
