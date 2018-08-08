#ifndef NODE_H
#define NODE_H

template <typename E>
class Node {
	public:
		Node();
		Node(const E &e);
		const E & getElement() const;
		void setElement(const E &e);
	protected:
		E element;
};

template <typename E>
Node<E>::Node() :
	element(0) {}

template <>
Node<std::string>::Node() :
	element("") {}

template <typename E>
Node<E>::Node(const E &e) {
	element = e;
}

template <typename E>
const E & Node<E>::getElement() const {
	return element;
}

template <typename E>
void Node<E>::setElement(const E &e) {
	element = e;
}

template <typename E>
std::ostream & operator<<(std::ostream &os, Node<E> &n) {
	return os << n.getElement();
}

template <typename E>
std::ostream & operator<<(std::ostream &os, const Node<E> &n) {
	return os << n.getElement();
}


#endif
