public class ArrayStack {
	private int size = 0;
	private String stack[];
	

	public ArrayStack() {
		stack = new String[10];
	}

	public ArrayStack(int s) {
		stack = new String[s];
	}

	public void push(String s) {
		if(this.isFull()) {
			System.out.println("Stack is full!");
			return;
		}
		stack[size++] = s;
	}

	public String pop() {
		if(this.isEmpty()) {
			System.out.println("Stack is empty!");
			return null;
		}
		String s = stack[--size];	
		stack[size] = null;
		return s;
	}

	public String top() {
		if(this.isEmpty()) {
			System.out.println("Stack is empty!");
			return null;
		}
		return stack[size-1];
	}

	public int size() {
		return this.size;
	}
	
	public Boolean isEmpty() {
		return (size == 0);
	}

	public Boolean isFull() {
		return (size == stack.length);
	}

	public String[] getStack() {
		return this.stack;
	}

	public static void main(String args[]) {
		ArrayStack s = new ArrayStack();
		System.out.println(s.getStack().length);
		s.push("David");
		System.out.println(s.top());
		s.push("Emily");
		s.push("Ashleigh");
		s.push("Martina");
		s.push("Bradley");

		System.out.println("Top is: " + s.top());
		System.out.println("Size is: " + s.size());

		for(int i = s.size(); i > 0; i--) {
			System.out.println(s.pop());
			System.out.println("New top is " + s.top());
		}
	}
}

