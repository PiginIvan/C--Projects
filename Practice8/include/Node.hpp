#ifndef NODE_HPP
#define NODE_HPP
#include <memory>

template<class T>
class Node {
private:
	T val;
	std::unique_ptr<Node> next;
public:
	Node();
	Node(T x);

	T get_val();
	T& get_ref_val();
	Node* get_next();
	void set_next(Node<T>* other);
};

#endif