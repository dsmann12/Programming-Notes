#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BTNode.h"

class BinaryTree {
	public:
		BinaryTree();
		~BinaryTree();
		void addLeft(BTNode<E> &n, const E &e);
		void addRight(BTNode<E> &n, const E &e);
		void insert(const E &e);
		BTNode<E> * search(const E &e, BTNode<E> &n);
		void remove(const E &e);
		int size() const;
		int depth() const;
		int height() const;
		bool empty() const;
	private:
		BTNode<E> root;
		std::vector
		int _size, _depth, _height;
};

template <typename E>
BinaryTree<E>::BinaryTree() :
	_size(0), _depth(0), _height(0) {}

template <typename E>
BinaryTree<E>::~BinaryTree() {}

template <typename E>
BTNode<E> * BinaryTree<E>::search(const E &e, BTNode<E> &n) {
	
}

template <typename E>
void BinaryTree<E>::addLeft(BTNode<E> &n, const E &e) {
	
}

#endif
