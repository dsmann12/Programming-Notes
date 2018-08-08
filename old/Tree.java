public class Tree<E> {
	private TNode<E> root;
	private int size;

	public Tree() {
		size = 0;
		root = null;
	}

	public TNode<E> addNode(TNode<E> p, E e) {
		if(p == null) {
			root = new TNode<E>(e);
			return root;
		}
		
		TNode<E> n = new TNode<E>(e, p);
		p.children.add(n);
		size++;

		return n;
	}

	public void removeNode(TNode<E> n) {

	}

	public boolean isRoot(TNode<E> n) {
		return (root == n);
	}

	public int height(TNode<E> n) {
		//height is max depth of children
		int h = 0;
		
		for(TNode<E> c : n.getChildren()) {
			h = Math.max(h, 1+height(c));
		}

		return h;
	}

	public boolean isEmpty() {
		return (size == 0);
	}

	public int getSize() {
                return size;
        }

        public TNode<E> getRoot() {
                return root;
        }

	public void postOrderPrint(int i, TNode<E> n) {
		//print root at 0 indent
		//print children at 4(1) indent
		for(int j = 0; j < i; j++) {
			System.out.print("    ");
		}
		int d = depth(n);
		int h = height(n);
		System.out.println(n.getElement() + " Depth: " + d
					+ " Height: " + h);
		
		for(TNode<E> c : n.getChildren()) {
			postOrderPrint(i+1, c);
		}
	}

	public int depth(TNode<E> n) {
		//depth is number of ancestors
		//root is 0
		if(isRoot(n)) {
			return 0;
		}

		return 1 + depth(n.getParent());
	}
	
	public static void main(String args[]) {
		Tree<String> tree = new Tree<String>();
		TNode<String> root = tree.addNode(tree.getRoot(), "/");

		TNode<String> usr = tree.addNode(tree.getRoot(),"usr");
		TNode<String> bin = tree.addNode(tree.getRoot(), "bin");
		TNode<String> home = tree.addNode(tree.getRoot(), "home");

		tree.addNode(home, "david");		
		tree.addNode(usr, "share");
		tree.addNode(bin, "java");
		tree.addNode(bin, "glibc");

		tree.postOrderPrint(0, tree.getRoot());	
	}
}
