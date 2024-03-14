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

template<class T>
T Node<T>::get_val() {
	return val;
}

template<class T>
T& Node<T>::get_ref_val() {
	return val;
}

template<class T>
Node<T>* Node<T>::get_next() {
	return next;
}

template<class T>
void Node<T>::set_next(Node<T>* other) {
	next = other;
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

template<>
char Node<char>::get_val() {
	return val;
}

template<>
char& Node<char>::get_ref_val() {
	return val;
}

template<>
Node<char>* Node<char>::get_next() {
	return next;
}

template<>
void Node<char>::set_next(Node<char>* other) {
	next = other;
}


template class Node<int>;
template class Node<double>;