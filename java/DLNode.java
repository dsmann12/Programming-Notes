//E element
//DLNode prev, next
//getters and setters
//compareTo
public class DLNode<E extends Comparable<E>> {
	private E element;
	private DLNode<E> prev;
	private DLNode<E> next;

	public DLNode() {
		this.element = null;
		this.prev = null;
		this.next = null;
	}

	public DLNode(E e) {
		this.element = e;
		this.prev = null;
		this.next = null;
	}

	public DLNode(E e, DLNode<E> p, DLNode<E> n) {
		this.element = e;
		this.prev = p;
		this.next = n;
	}

	public E getElement() {
		return this.element;
	}

	public void setElement(E e) {
		this.element = e;
	}

	public DLNode<E> getPrev() {
		return this.prev;
	}

	public void setPrev(DLNode<E> n) {
		this.prev = n;
	}

	public DLNode<E> getNext() {
		return this.next;
	}	
	
	public void setNext(DLNode<E> n) {
		this.next = n;
	}
}
