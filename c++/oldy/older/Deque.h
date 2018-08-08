#ifndef DEQUE_H
#define DEQUE_H

#include "DoublyLinkedList.h"

template <typename E>
class Deque : public DoublyLinkedList<E> {
	public:
		Deque();
		~Deque();
};

template <typename E>
Deque<E>::Deque() :
	DoublyLinkedList<E>::DoublyLinkedList() {}

template <typename E>
Deque<E>::~Deque() {}

#endif
