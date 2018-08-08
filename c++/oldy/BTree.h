#ifndef BTREE_H
#define BTREE_H

#include <algorithm>
#include "BTNode.h"

template <typename E>
class BTree {
	public:
		BTree();
		~BTree();
		BTNode<E> & search(const E &key, BTNode<E> *n);
		BTNode<E> & insert(const E &e);
		void expand(BTNode<E> &n, const E &e);
		void erase(BTNode<E> *n, BTNode<E> *p);
		void remove(const E &e);
		void remover(BTNode<E> &pos);
		void calculateDepth(BTNode<E> &n);
		void calculateHeight(BTNode<E> &n);
		const int depth() const;
		const int height(BTNode<E> *n);
		BTNode<E> & root();
		void print(BTNode<E> &n, int indent);
	protected:
		BTNode<E> * _root;
		int _size, _height, _depth;
};

template <typename E>
BTree<E>::BTree() :
	_size(0), _height(0), _depth(0)
{
	_root = new BTNode<E>;
}

template <typename E>
BTree<E>::~BTree() {
	delete _root;
}

template <typename E>
BTNode<E> & BTree<E>::search(const E &key, BTNode<E> *n) {
	if(n->isExternal()) {
		return *n;
	}	

	if(key < n->element()) {
		return search(key, n->left());
	}
	else if(key > n->element()) {
		return search(key, n->right());
	}
	else {
		return *n;
	}
}

template <typename E>
void BTree<E>::expand(BTNode<E> &n, const E &e) {
	n.set(e);
	n.setLeft(new BTNode<E>);
	n.setRight(new BTNode<E>);
}

template <typename E>
BTNode<E> & BTree<E>::insert(const E &e) {
	BTNode<E> &pos = search(e, _root);
	while(pos.isInternal()) {
		pos = search(e, pos.left());
	}

	expand(pos, e);
	_size++;
}

template <typename E>
BTNode<E> & BTree<E>::root() {
	return *_root;
}

template <typename E>
void BTree<E>::erase(BTNode<E> *n, BTNode<E> *r) {
	if(n->isRoot()) {
		_root = r;
		r->setParent(0);
	}
	else {
		BTNode<E> *p = n->parent();
		if(p->left() == n) {
			p->setLeft(r);
		}
		else {
			p->setRight(r);
		}
	}
	_size--;
	
	n->setLeft(new BTNode<E>);
	n->setRight(new BTNode<E>);
	delete n;
}

template <typename E>
void BTree<E>::remover(BTNode<E> &pos) {
	if(pos.right()->isExternal()) {
		if(pos.left()->isExternal()) {
			erase(&pos, new BTNode<E>);
		}
		else {
			erase(&pos, pos.left());
		}
	}
	else if(pos.left()->isExternal()) {
		erase(&pos, pos.right());
	}
	else {
		BTNode<E> *r = pos.right();
		while(r->left()->isInternal()) {
			r = r->left();
		}
		
		E temp = r->element();
		r->set(pos.element());
		pos.set(temp);
		remover(*r);
	}
}

template <typename E>
void BTree<E>::remove(const E &e) {
	BTNode<E> &pos = search(e, _root);
	if(pos.isExternal()) {
		return;
	}
	else {
		remover(pos);
	}
}

template <typename E>
const int BTree<E>::height(BTNode<E> *n) {
	if(n->isExternal()) {
		n->setHeight(-1);
		return -1;
	}
	else {
		int h = std::max(height(n->left()), height(n->right())) + 1;
		n->setHeight(h);
		return h;
	}
}

template <typename E>
void BTree<E>::print(BTNode<E> &n, int indent) {
	for(int i = indent; i > 0; i--) {
		std::cout << "    ";
	}
	
	if(n.isRoot()) {
		if(n.isExternal()) {
			std::cout << "Empty Tree!\n";
			return;
		}		
		std::cout << n << std::endl;
	}
	else if (&n == n.parent()->left()) {
		std::cout << "Left: " << n << std::endl;
	}
	else {
		std::cout << "Rigtht: " << n << std::endl;
	}

	if(n.hasLeft() && n.left()->isInternal()) {
		print(*n.left(), indent+1);
	}
	else {		
		for(int i = indent+1; i > 0; i--) {
			std::cout << "    ";
		}
		std::cout << "Left: " << std::endl;
	}
	if(n.hasRight() && n.right()->isInternal()) {
		print(*n.right(), indent+1);
	}
	else {

		for(int i = indent+1; i > 0; i--) {
			std::cout << "    ";
		}
		std::cout << "Right: " << std::endl;
	}
}

#endif
