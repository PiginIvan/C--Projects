#ifndef NODE_HPP
#define NODE_HPP

template<class T>
class Node {
public:
	T val;
	Node* next;
	Node();
	Node(T x);
};

#endif