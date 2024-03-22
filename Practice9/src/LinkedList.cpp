#include "LinkedList.hpp"
#include <iostream>
#include <string>

template<>
void LinkedList<char>::push_back(char x);

template<class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(std::initializer_list<T> init_list) {
	head = nullptr;
	for (auto& x : init_list) {
		push_back(x);
	}
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& other) {
	head = nullptr;
	Node<T>* tmp = other.head;
	while (tmp) {
		push_back(tmp->get_val());
		tmp = tmp->get_next();
	}
}

template<class T>
void LinkedList<T>::push_back(T x) {
	if (!head) {
		head = new Node<T>(x);
	}
	else {
		Node<T>* prev = nullptr;
		Node<T>* tmp = head;
		while (tmp->get_next()) {
			tmp = tmp->get_next();
		}
		tmp->set_next(new Node<T>(x));
	}
}

template<class T>
void LinkedList<T>::insert(int index, T x) {
	if (!head) {
		head = new Node<T>(x);
	}
	else {
        int cur_index = 0;
		Node<T>* prev = nullptr;
        Node<T>* newNode = new Node<T>(x);
		Node<T>* tmp = head;
		while (tmp->get_next() && cur_index + 1 != index) {
			tmp = tmp->get_next();
            cur_index++;
		}
		newNode->set_next(tmp->get_next());
        tmp->set_next(newNode);
	}
}

template<class T>
void LinkedList<T>::push_front(T x) {
	if (!head) {
		head = new Node<T>(x);
	}
	else {
		Node<T>* tmp = head;
		head = new Node<T>(x);
		head->set_next(tmp);
	}
}

template<class T>
void LinkedList<T>::pop_back() {
	if (!head) {
		return;
	}
	else {
		Node<T>* tmp = head;
		Node<T>* prev = nullptr;
		while (tmp->get_next()) {
			prev = tmp;
			tmp = tmp->get_next();
		}
		if (prev) prev->set_next(nullptr);
		delete tmp;
	}
}

template<class T>
void LinkedList<T>::pop_front() {
	if (!head) {
		return;
	}
	else {
		Node<T>* tmp = head->get_next();
		delete head;
		head = tmp;
	}
}

template<class T>
void LinkedList<T>::print_list_iters() const{
	for (iter it = begin(); it != end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<class T>
void LinkedList<T>::print_list() {
	Node<T>* tmp = head;
	while (tmp) {
		std::cout << tmp->get_val() << " ";
		tmp = tmp->get_next();
	}
	std::cout << std::endl;
}

template<class T>
bool LinkedList<T>::find(T x) {
	Node<T>* tmp = head;
	while (tmp) {
		if (tmp->get_val() == x) return true;
		tmp = tmp->get_next();
	}
	return false;
}

template<class T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList& other)
{
	return LinkedList(other);
}

template<>
LinkedList<char>::LinkedList() {
	head = nullptr;
}

template<>
LinkedList<char>::LinkedList(std::initializer_list<char> init_list) {
	head = nullptr;
	for (auto& x : init_list) {
		push_back(x);
	}
}

template<>
LinkedList<char>::LinkedList(const LinkedList& other) {
	head = nullptr;
	Node<char>* tmp = other.head;
	while (tmp) {
		push_back(tmp->get_val());
		tmp = tmp->get_next();
	}
}

template<>
LinkedList<char>::LinkedList(const std::string& s) {
	head = nullptr;
	for (char x : s) {
		push_back(x);
	}
}

template<>
void LinkedList<char>::push_back(char x) {
	if (!head) {
		head = new Node<char>(x);
	}
	else {
		Node<char>* prev = nullptr;
		Node<char>* tmp = head;
		while (tmp->get_next()) {
			tmp = tmp->get_next();
		}
		tmp->set_next(new Node<char>(x));
	}
}

template<>
void LinkedList<char>::push_front(char x) {
	if (!head) {
		head = new Node<char>(x);
	}
	else {
		Node<char>* tmp = head;
		head = new Node<char>(x);
		head->set_next(tmp);
	}
}

template<>
void LinkedList<char>::pop_back() {
	if (!head) {
		return;
	}
	else {
		Node<char>* tmp = head;
		Node<char>* prev = nullptr;
		while (tmp->get_next()) {
			prev = tmp;
			tmp = tmp->get_next();
		}
		if (prev) prev->set_next(nullptr);
		delete tmp;
	}
}

template<>
void LinkedList<char>::pop_front() {
	if (!head) {
		return;
	}
	else {
		Node<char>* tmp = head->get_next();
		delete head;
		head = tmp;
	}
}

template<>
void LinkedList<char>::print_list() {
	Node<char>* tmp = head;
	while (tmp) {
		std::cout << tmp->get_val() << " ";
		tmp = tmp->get_next();
	}
	std::cout << std::endl;
}

template<>
bool LinkedList<char>::find(char x) {
	Node<char>* tmp = head;
	while (tmp) {
		if (tmp->get_val() == x) return true;
		tmp = tmp->get_next();
	}
	return false;
}

template<>
LinkedList<char> LinkedList<char>::operator=(const LinkedList& other)
{
	return LinkedList(other);
}

template class LinkedList<int>;
template class LinkedList<double>;