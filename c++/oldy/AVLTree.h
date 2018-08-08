#ifndef AVLTREE_H
#define AVLTREE_H

#include "BTree.h"

template <typename E>
class AVLTree : public BTree<E> {
	public:
		AVLTree();
		~AVLTree();
		BTNode<E> & inserter(const E &key);
		void rebalance(BTNode<E> &n);
		void restructure(BTNode<E> &n);
		void rotate(BTNode<E> &n);
		void relink(BTNode<E> &p, BTNode<E> &c);		
	protected:
};

template <typename E>
AVLTree<E>::AVLTree() :
	BTree<E>() {}

template <typename E>
AVLTree<E>::~AVLTree() {}

BTNode<E> & AVLTree<E>::inserter(const E &key) {
	BTNode<E> &pos = insert(key);
	height(_root);
	rebalance(pos);
}

template <typename E>
void restructure(BTNode<E> &n) {

}

template <typename E>
void AVLTree<E>::rebalance(BTNode<E> &n) {
	while(n != 0) {
		if(!n.isBalanced) {
			restructure(tallestChild(tallestChild(n)));
		}
		n = *n.parent();
	}
	
		
}
#endif
