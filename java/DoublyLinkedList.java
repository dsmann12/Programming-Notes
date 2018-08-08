//addFirst(DLNode), addLast(DLNode) addBefore(DLNode, DLNode), addAfter(DLNode, DLNode)
//removeFirst(), removeLast(), remove()
//searchList O(n)
//isEmpty()
//compare()
public class DoublyLinkedList<E extends Comparable<E>> {
        private int size = 0;
        private DLNode<E> header;
        private DLNode<E> trailer;

        public DoublyLinkedList() {
                this.size = 0;
                this.header = new DLNode<E>();
                this.trailer = new DLNode<E>();

                header.setNext(trailer);
                trailer.setPrev(header);
        }

	//oldFirst is header.next
	//oldFirst.prev now points to n
	//header.next now points to n
	//create new node
	//increment size
	public void addFirst(E e) {
		DLNode<E> oldFirst = this.header.getNext();
		DLNode<E> n = new DLNode<E>(e, header, oldFirst);

		oldFirst.setPrev(n);
		
		header.setNext(n);
	
		size++;	
	}

	//oldLast is trailer.prev
	//oldLast.next is now n
	//trailer.prev is now n
	//create new node
	//increment size
	public void addLast(E e) {
		DLNode<E> oldLast = trailer.getPrev();
		DLNode<E> n = new DLNode<E>(e, oldLast, trailer);
		oldLast.setNext(n);
		trailer.setPrev(n);
		size++;		
	}

	public void addBefore(DLNode<E> n, E e) {
		DLNode<E> oldB = n.getPrev();
		DLNode<E> b = new DLNode<E>(e, oldB, n);
		oldB.setNext(b);
		n.setPrev(b);
		size++;
	}

	public void addAfter(DLNode<E> n, E e) {
		DLNode<E> oldA = n.getNext();
		DLNode<E> a = new DLNode<E>(e, n, oldA);
		oldA.setPrev(a);
		n.setNext(a);
		size++;
	}
	
	public E remove(DLNode<E> n) {
		if(isEmpty()) {
			System.out.println("List is empty!");
			return null;
		}
		DLNode<E> oldP = n.getPrev();
		DLNode<E> oldN = n.getNext();
		
		oldP.setNext(oldN);
		oldN.setPrev(oldP);

		n.setNext(null);
		n.setPrev(null);

		E e = n.getElement();
		n.setElement(null);
		
		size--;
			
		return e;
	}

	public E removeLast() {
		if(isEmpty()) {
			System.out.println("List is empty!");
			return null;
		}
		
		size--;

		return remove(trailer.getPrev());
	}

	public E removeFirst() {
		if(isEmpty()) {
			System.out.println("List is empty");
			return null;
		}
		
		size--;
	
		return remove(header.getNext());
	}

	public DLNode<E> getFirst() {
		if(isEmpty()) {
			return null;
		}

		return this.header.getNext();
	}

	public DLNode<E> getLast() {
		if(isEmpty()) {
			return null;
		}

		return this.trailer.getPrev();
	}

	public boolean isEmpty() {
		return (size == 0);
	}
		
	public int compare(DLNode<E> n, DLNode<E> m) {
		E ne = n.getElement();
		E me = m.getElement();

		return ne.compareTo(me);
	}

	public void printList() {
		if(isEmpty()) {
			System.out.println("List is empty!");
			return;
		}

		DLNode<E> n = header.getNext();
		while(n.getNext() != null) {
			System.out.println(n.getElement().toString());
			n = n.getNext();
		}
	}

	public DLNode<E> find(E e) {
		DLNode<E> n = header.getNext();
		while(n.getNext() != null) {
			int c = e.compareTo(n.getElement());
			if(c == 0) {
				return n;
			}
			
			n = n.getNext();
		}
		
		return null;	
	}
	
	//quick way of accessing data in a list
	public static void main(String args[]) {
		DoublyLinkedList<String> l = new DoublyLinkedList<String>();
		l.addLast("David");
		l.addLast("Emilly");
		l.addLast("Bradley");
	
		l.printList();
		
		DLNode<String> n = l.find("Bradley");
		l.addBefore(n, "Martina");
		n = l.find("Martina");
		l.addAfter(n, "Ashleigh");
	
		System.out.println();
		l.printList();
	}
}

