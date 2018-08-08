public class DoublyLinkedList {
	private DLNode header = null;
	private DLNode trailer = null;
	private int size;

	public DoublyLinkedList() {
		this.size = 0;
		this.header = new DLNode();
		this.trailer = new DLNode();
		header.setNext(trailer);
		trailer.setPrev(header);
	}

	public void addFirst(DLNode n) {
		DLNode first = header.getNext();
		header.setNext(n);
		n.setNext(first);
		first.setPrev(n);		
		n.setPrev(header);
		size++;
	}

	public void addLast(DLNode n) {
		DLNode last = trailer.getPrev();
		trailer.setPrev(n);
		last.setNext(n);
		n.setPrev(last);
		n.setNext(trailer);
		size++;
	}

	public DLNode getFirst() {
		return header.getNext();
	}

	public DLNode getLast() {
		return trailer.getPrev();
	}

	public DLNode removeFirst() {
		DLNode first = header.getNext();
		DLNode newFirst = first.getNext();
		header.setNext(newFirst);
		newFirst.setPrev(header);
		size--;
		
		return first;
		
	}

	public DLNode removeLast() {
		DLNode last = trailer.getPrev();
		DLNode newLast = last.getPrev();
		trailer.setPrev(newLast);
		newLast.setNext(trailer);
		size--;

		return last;
	}

	public boolean isEmpty() {
		return (size == 0);
	}

	public void printList() {
		DLNode n = header.getNext();
		while(n.getNext() != null) {
			System.out.println(n.getElement());
			n = n.getNext();
		}
	}

	public static void main(String args[]) {
		DoublyLinkedList dl = new DoublyLinkedList();
                String s1 = "David";
                String s2 = "Emily";
                String s3 = "Ashleigh";
                String s4 = "Martina";
                String s5 = "Bradley";
                String names[] = {s1, s2, s3, s4, s5};

                for(String s : names) {
                        DLNode<String> n = new DLNode<String>(s);
                        dl.addLast(n);
                //      sl.printList();
                }

		dl.printList();

	}
}
