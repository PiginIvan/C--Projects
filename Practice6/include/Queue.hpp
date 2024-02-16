#ifndef QUEUE
#define QUEUE
#include <vector>

class Queue {
public:
	std::vector<int> data;
	int size;

	Queue();
	Queue(int size);
	Queue(const Queue& other);

	int front();
	int back();
	void enqueue(int elem);
	int dequeue();

	int& operator[](int index);
};

#endif