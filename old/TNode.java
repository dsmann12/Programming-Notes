import java.util.ArrayList;

public class TNode<E> extends Node<E> {
	protected TNode<E> parent;
	protected ArrayList<TNode<E>> children;
	
	public TNode() {
		this.element = null;
		this.parent = null;
		this.children = new ArrayList<TNode<E>>();
	}

	public TNode(E element) {
		this.element = element;
		this.parent = null;
		this.children = new ArrayList<TNode<E>>();
	}

	public TNode(TNode<E> parent) {
		this.parent = parent;
		this.element = null;
		this.children = new ArrayList<TNode<E>>();
	}

	public TNode(E element, TNode<E> parent) {
		this.element = element;
		this.parent = parent;
		this.children = new ArrayList<TNode<E>>();
	}

	public TNode<E> getParent() {
		return this.parent;
	}

	public void setParent(TNode<E> p) {
		this.parent = p;
	}

	public ArrayList<TNode<E>> getChildren() {
		return this.children;
	}

	public void setChildren(ArrayList<TNode<E>> children) {
		this.children = children;
	}

	public boolean isExternal() {
		return children.isEmpty();
	}

	public boolean isInternal() {
		return(!isExternal());
	}
}
