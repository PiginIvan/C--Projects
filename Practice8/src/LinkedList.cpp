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
		push_back(tmp->val);
		tmp = tmp->next;
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
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = new Node<T>(x);
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
		head->next = tmp;
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
		while (tmp->next) {
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev) prev->next = nullptr;
		delete tmp;
	}
}

template<class T>
void LinkedList<T>::pop_front() {
	if (!head) {
		return;
	}
	else {
		Node<T>* tmp = head->next;
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
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

template<class T>
bool LinkedList<T>::find(T x) {
	Node<T>* tmp = head;
	while (tmp) {
		if (tmp->val == x) return true;
		tmp = tmp->next;
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
		push_back(tmp->val);
		tmp = tmp->next;
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
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = new Node<char>(x);
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
		head->next = tmp;
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
		while (tmp->next) {
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev) prev->next = nullptr;
		delete tmp;
	}
}

template<>
void LinkedList<char>::pop_front() {
	if (!head) {
		return;
	}
	else {
		Node<char>* tmp = head->next;
		delete head;
		head = tmp;
	}
}

template<>
void LinkedList<char>::print_list() {
	Node<char>* tmp = head;
	while (tmp) {
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

template<>
bool LinkedList<char>::find(char x) {
	Node<char>* tmp = head;
	while (tmp) {
		if (tmp->val == x) return true;
		tmp = tmp->next;
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