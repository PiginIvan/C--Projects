#ifndef MYSTACK_HPP
#define MYSTACK_HPP

class MyStack {
private:
	int size;
	int* data;
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