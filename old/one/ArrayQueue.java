public class ArrayQueue {
	String queue[];
	int size = 0;
	int f = 0;
	int r = 0;
	
	public ArrayQueue() {
		queue = new String[10];
	}

	public ArrayQueue(int s) {
		queue = new String[s];
	}
	//adds to rear
	//arrayQueue is full is r = 9
	//size is (N - f + r) mod N
	
	public void enqueue(String s) {
		if(isFull()) {
			System.out.println("Queue is full!");
			return;
		}
		queue[r] = s;
		r = (r + 1) % queue.length;
		size++;	
	}

	public String dequeue() {
		if(isEmpty()) {
			System.out.println("Queue is empty!");
			return null;
		}

		String s = queue[f];
		f = (f + 1) % queue.length;
		size--;
		
		return s;
	}

	public Boolean isFull() {
		return (size == (queue.length - 1));
	}	

	public Boolean isEmpty() {
		return (f == r);
	}

	public String front() {
		return queue[f];
	}

	public static void main(String args[]) {
		ArrayQueue q = new ArrayQueue();
		
		q.enqueue("David");
		q.enqueue("Emily");
		q.enqueue("Ashleigh");
		q.enqueue("Martina");
		q.enqueue("Bradley");

		while(!q.isEmpty()) {
			System.out.println(q.dequeue());
		}

		System.out.println();
		q = new ArrayQueue(4);
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
