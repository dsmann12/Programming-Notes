#ifndef NODE_H
#define NODE_H

template <typename E>
class Node {
	public:
		Node();
		Node(const E &e);
		const E & element() const;
		void set(const E &e);
	protected:
		E _element;		
};

template <typename E>
Node<E>::Node() :
	_element(0) {}

template <>
Node<std::string>::Node() :
	_element("") {}

template <typename E>
Node<E>::Node(const E &e) :
	_element(e) {}

template <typename E>
const E & Node<E>::element() const {
	return _element;
}

template <typename E>
void Node<E>::set(const E &e) {
	_element = e;
}

template <typename E>
std::ostream & operator<<(std::ostream &os, const Node<E> &n) {
	return os << n.element();
}

#endif
