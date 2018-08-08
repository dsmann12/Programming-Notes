#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template <typename E>
class Node {
	public:
		Node();
		Node(const E &e); //do not modify argument
		void setElement(const E &e);
		const E & getElement() const;
	protected:
		E element;
};

template <typename E>
Node<E>::Node() :
	element(0)
{}

template <>
Node<string>::Node() {
	element = "";
}

template <typename E>
Node<E>::Node(const E &e) :
	element(e)
{
}

//want to return reference to element because element could be class
//should be const member function because it will not modify object
//but a reference can be used to change value of element
template <typename E>
const E & Node<E>::getElement() const {
	return element;
}

template <typename E>
void Node<E>::setElement(const E &e) {
	element = e;
}

template <typename E>
ostream & operator<<(ostream &os, Node<E> &n) {
	return os << n.getElement();
}

template <typename E>
class LNode : public Node<E> {
	public:
		LNode();
		LNode(const E &e);
		//setNext
		//getNext
		void setNext(LNode<E> *n);
		LNode<E> * getNext() const;
	private:
		LNode<E> *next;	
};

template <typename E>
LNode<E>::LNode() {
	next = NULL;
}

template <typename E>
LNode<E>::LNode(const E &e) :
	Node<E>(e)
{
	next = NULL;	
}

template <typename E>
void LNode<E>::setNext(LNode<E> *n) {
	next = n;
}

//does pointer provide ability to modify next?
template <typename E>
LNode<E> * LNode<E>::getNext() const {
	return next;
}

template <typename E>
class DLNode : public Node<E> {
	public:
		DLNode();
		DLNode(const E &e);
		void setPrev(DLNode<E> *n);
		DLNode<E> * getPrev() const;
		void setNext(DLNode<E> *n);
		DLNode<E> * getNext() const;
	private:
		DLNode<E> *prev;
		DLNode<E> *next;
};

template <typename E>
DLNode<E>::DLNode() {
	prev = NULL;
	
	//next needs to be a DLNode
	
}

template <typename E>
DLNode<E>::DLNode(const E &e) :
	Node<E>(e)
{
	prev = NULL;	
}

template <typename E>
void DLNode<E>::setPrev(DLNode<E> *n) {
	prev = n;
}

template <typename E>
DLNode<E> * DLNode<E>::getPrev() const {
	return prev;
}

template <typename E>
void DLNode<E>::setNext(DLNode<E> *n) {
	next = n;
}

template <typename E>
DLNode<E> * DLNode<E>::getNext() const {
	return next;
}

#endif
