#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "Node.hpp"
#include <string>

template<class T>
class LinkedList {
private:
	Node<T>* head;
	class iter {
	private:
		Node<T>* cur;
	public:
		iter(Node<T>* curNode) { cur = curNode; };

		T& operator *() { return cur->get_ref_val(); };
		iter& operator ++() { cur->set_next(cur->get_next()); return *this; };
		bool operator !=(const iter& other) { return cur != other.cur;  };
	};

public:

	iter begin() const { return iter(head); };
	iter end() const { return iter(nullptr); };

	LinkedList();
	LinkedList(std::initializer_list<T> init_list);
	LinkedList(const LinkedList& other);
	LinkedList(const std::string& s);

	void print_list_iters() const;
	void push_back(T x);
	void push_front(T x);
	void insert(int index, T x);
	void pop_back();
	void pop_front();
	bool find(T x);
	void print_list();

	LinkedList operator =(const LinkedList& other);

};

#endif 