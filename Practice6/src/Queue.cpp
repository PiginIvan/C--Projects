#include "Queue.hpp"

Queue::Queue() { this->size = 0; }

Queue::Queue(int size) { this->size = size; data.reserve(size); }

Queue::Queue(const Queue& other) { this->size = other.size; this->data = other.data; }

int Queue::front() { return this->data[0]; }

int Queue::back() { return this->data[size - 1]; }

void Queue::enqueue(int elem) { this->data.push_back(elem); }

int Queue::dequeue() { int ans = this->data[0]; this->size--; this->data.erase(data.begin()); return ans; }

int& Queue::operator[](int index) { return this->data[index]; }