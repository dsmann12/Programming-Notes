#ifndef TNODE_H
#define TNODE_H

#include "Node.h"
#include <vector>

template <typename E>
class TNode : public Node<E> {
	public:
		TNode();
		TNode(const E &e);
		~TNode();
		std::vector<TNode<E> *> children();
		TNode<E> * child(const int i);
		void addChild(TNode<E> &n);
		TNode<E> * parent();
		void setParent(TNode<E> &n);
		const int height() const;
		const int depth() const;
		bool isExternal() const;
		bool isInternal() const;
		bool isRoot() const;
	protected:
		TNode<E> *_parent;
		int _height, _depth;
		std::vector<TNode<E> *> _children;
};


template <typename E>
TNode<E>::TNode() :
	Node<E>::Node(), _parent(0), _height(0),
	_depth(0) 
{
	_children = *new std::vector<TNode<E> *>();	
}

template <typename E>
TNode<E>::TNode(const E &e) :
	Node<E>::Node(e), _parent(0), _height(0),
	_depth(0)
{
	_children = *new std::vector<TNode<E> *>();
}

template <typename E>
TNode<E>::~TNode() {
	_children.clear();
}

template <typename E>
std::vector<TNode<E> *> TNode<E>::children() {
	return _children;
}

template <typename E>
TNode<E> * TNode<E>::child(const int i) {
	return _children[i];
}

template <typename E>
void TNode<E>::addChild(TNode<E> &n) {
	n.setParent(*this);
	_children.push_back(&n);
}

template <typename E>
TNode<E> * TNode<E>::parent() {
	return _parent;
}

template <typename E>
void TNode<E>::setParent(TNode<E> &n) {
	_parent = &n;
}

template <typename E>
const int TNode<E>::depth() const {
	return _depth;
}

template <typename E>
const int TNode<E>::height() const {
	return _height;
}

template <typename E>
bool TNode<E>::isExternal() const {
	return (_children.size() == 0);
}

template <typename E>
bool TNode<E>::isInternal() const {
	return (_children.size() > 0);
}

template <typename E>
bool TNode<E>::isRoot() const {
	return (_parent == 0);
}

#endif
