#include "Node.hpp"

template<class T>
Node<T>::Node() {
	val = 0;
	next = nullptr;
}

template<class T>
Node<T>::Node(T x) {
	val = x;
	next = nullptr;
}

template<>
Node<char>::Node() {
	val = 'a';
	next = nullptr;
}

template<>
Node<char>::Node(char x) {
	val = x;
	next = nullptr;
}

template class Node<int>;
template class Node<double>;