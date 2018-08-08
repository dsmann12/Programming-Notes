//Stores PQEntry<> objects
//is it a list or does it just store a list
//insert()
//removeMin()
//store min

public class UnsortedPriorityQueue<K extends Comparable<K>, V> {
	DLNode<PQEntry<K, V>> min = null;
	DoublyLinkedList<PQEntry<K, V>> pq = null;

	public UnsortedPriorityQueue() {
		this.pq = new DoublyLinkedList<PQEntry<K, V>>();
//		this.min = new DLNode<PQEntry<K, V>>();
	}

	public void insert(PQEntry<K, V> n) {
		pq.addLast(n);

		if( (min == null) || (n.getKey().compareTo(min.getElement().getKey()) < 0 )) {
			min = pq.getLast();
		}
	}

	public PQEntry<K, V> removeMin() {
		if(pq.isEmpty()) {
			System.out.println("List is empty!");
			return null;
		}

		PQEntry<K, V> m = pq.remove(min);
		if(pq.isEmpty()) {
			min = null;
			return m;
		}			
		
		min = pq.getFirst();	
		DLNode<PQEntry<K, V>> n = min.getNext();
	
		while(n.getNext() != null) {
			min = compareMin(n);
			n = n.getNext();			
		}
		

		return m;
	}

	public DLNode<PQEntry<K, V>> compareMin(DLNode<PQEntry<K, V>> e) {
		if((e.getElement().compareTo(min.getElement()) < 0)) {
			min = e;
		}

		return min;
	}

	

	public static void main(String args[]) {
		PQEntry<Integer, String> n1 = new PQEntry<Integer, String>(1, "David");
		DLNode<PQEntry<Integer, String>> d = new DLNode<PQEntry<Integer, String>>(n1);
		UnsortedPriorityQueue<Integer, String> pq = new UnsortedPriorityQueue<Integer, String>();
	
		pq.insert(n1);
		n1 = new PQEntry<Integer, String>(2, "Emily");
		pq.insert(n1);
	
		pq.pq.printList();
		
		n1 = new PQEntry<Integer, String>(4, "Martina");
		pq.insert(n1);
		n1 = new PQEntry<Integer, String>(3, "Ashliegh");
		pq.insert(n1);
		n1 = new PQEntry<Integer, String>(5, "Bradley");
		pq.insert(n1);

		System.out.println();
		
		pq.pq.printList();

		System.out.println("\nMin is: " + pq.min.getElement());

		n1 = pq.removeMin();
		
		System.out.println();

		pq.pq.printList();
		n1 = pq.removeMin();
		n1 = pq.removeMin();
		
		System.out.println();

		pq.pq.printList();

		pq.removeMin();

		System.out.println();
		
		pq.pq.printList();

		pq.removeMin();

		pq.removeMin();

		n1 = new PQEntry<Integer, String>(3, "Ashleigh");
		pq.insert(n1);

		System.out.println();
		pq.pq.printList();

		n1 = new PQEntry<Integer, String>(1, "David");
		pq.insert(n1);
		
		System.out.println();
		pq.pq.printList();
		
		pq.removeMin();

		System.out.println();
		pq.pq.printList();	
	}
}
