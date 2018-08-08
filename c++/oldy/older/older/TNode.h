#ifndef TNODE_H
#define TNODE_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Node.h"

using namespace std;

template <typename E>
class TNode : public Node<E> {
	public:
		TNode();
		TNode(const E &e);
		~TNode();
		vector<TNode<E> *> & getChildren();		
		TNode<E> & getChild(const int i);
		void addChild(TNode<E> &n);
		void setParent(TNode<E> &n);
		TNode<E> & getParent();
		const int getIndex() const;
		void setIndex(const int n);
		bool isExternal() const;
		bool isInternal() const;
		bool isRoot() const;
	protected:
		TNode<E> *parent;
		int index, height, depth;
		vector<TNode<E> *> children;	
};

template <typename E>
TNode<E>::TNode() {
	parent = 0;
	index = height = depth = 0;
}

template <typename E>
TNode<E>::TNode(const E &e) :
	Node<E>::Node(e)
{
	parent = 0;
	index = height = depth = 0;
}

template <typename E>
TNode<E>::~TNode() {
	children.clear();
}

template <typename E>
vector <TNode<E> *> & TNode<E>::getChildren() {
	return children;
}

template <typename E>
TNode<E> & TNode<E>::getChild(const int i) {
	return *children[i];	
}

template <typename E>
void TNode<E>::addChild(TNode<E> &n) {
	children.push_back(&n);
}

template <typename E>
void TNode<E>::setParent(TNode<E> &n) {
	parent = &n;
}

template <typename E>
TNode<E> & TNode<E>::getParent() {
	return *parent;	
}

template <typename E>
void TNode<E>::setIndex(const int n) {
	index = n;
}

template <typename E>
const int TNode<E>::getIndex() const {
	return index;
}

template <typename E>
bool TNode<E>::isExternal() const {
	return (children.size() == 0);
}

template <typename E>
bool TNode<E>::isInternal() const {
	return (!isExternal());
}

template <typename E>
bool TNode<E>::isRoot() const {
	return (parent == 0);
}

#endif
