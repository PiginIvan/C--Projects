#ifndef MYSTACK_HPP
#define MYSTACK_HPP
#include <memory>

class MyStack {
private:
	int size;
	std::unique_ptr<int[]> data;
	int count_elem;

public:
	MyStack(int size);
	~MyStack();

	int count();
	void push(int num);
	int pop();
	void isEmpty();

};


#endif