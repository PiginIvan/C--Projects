#include "MyStack.hpp"
#include <iostream>

MyStack::MyStack(int size) {
    this->size = size;
    this->data = new int[size];
    this->count_elem = 0;
}

MyStack::~MyStack() {
    delete[] data;
    this->size = 0;
    this->count_elem = 0;
}

int MyStack::count() {
    return this->count_elem;
}

void MyStack::push(int num) {
    if (this->count_elem != size) this->data[this->count_elem++] = num;
    else std::cout << "Stack is overflow, can't push elem" << std::endl;
}

int MyStack::pop() {
    if (this->count_elem != 0) {
        return this->data[--this->count_elem];
    }
    else {
        std::cout << "Stack is empty, can't pop elem" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void MyStack::isEmpty() {
    if (this->count_elem == 0) std::cout << "Stack is empty" << std::endl;
    else std::cout << "Stack is not empty" << std::endl;
}

