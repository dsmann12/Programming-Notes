public class BTNode<E> extends Node<E> {
	private BTNode<E> parent;
	private BTNode<E> left;
	private BTNode<E> right;

	public BTNode() {
		this.element = null;
		this.left = null;
		this.right = null;
		this.parent = null;
	}

	public BTNode(E e) {
		this.element = e;
		this.left = null;
		this.right = null;
		this.parent = null;
	}

	public BTNode(BTNode<E> p) {
		this.element = null;
		this.parent = p;
		this.left = null;
		this.right = null;
	}

	public BTNode(E e, BTNode<E> p) {
		this.element = e;
		this.parent = p;
		this.left = null;
		this.right = null;
	}

	public BTNode<E> getLeft() {
		return this.left;
	}

	public void setLeft(BTNode<E> n) {
		this.left = n;
	}

	public BTNode<E> getRight() {
		return this.right;
	}

	public void setRight(BTNode<E> n) {
		this.right = n;
	}

	public boolean isExternal() {
		return((this.left == null) && (this.right == null));
	}

	public boolean isInternal() {
		return (!isExternal());
	}
}
