#ifndef MYSTACK_HPP
#define MYSTACK_HPP

class MyStack {
public:
	int size;
	int* data;
	int count_elem;

	MyStack(int size);
	~MyStack();

	int count();
	void push(int num);
	int pop();
	void isEmpty();

};


#endif