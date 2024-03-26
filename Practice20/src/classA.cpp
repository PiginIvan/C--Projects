#include "classA.hpp"
#include <iostream>

A::A(int number) {
    _number = new int(number);  
    std::cout << "class A constructor: " << *_number << std::endl;
}

A::A(const A& other) {
    _number = new int(*other._number);
    std::cout << "class A copy constructor: " << *_number << std::endl;
}

A::A(A&& other) {
    _number = other._number; 
    other._number = nullptr;
    std::cout << "class A move constructor: " << *_number << std::endl;
}

A& A::operator=(const A& other) {
    if (this != &other) {
        delete _number;
        _number = new int(*other._number);
        std::cout << "class A copy assignment operator: " << *_number << std::endl;
    }
    return *this;
}

A& A::operator=(A&& other) {
    if (this != &other) {
        delete _number;
        _number = new int(*other._number);
        other._number = nullptr;
        std::cout << "class A move assignment operator: " << *_number << std::endl;
    }
    return *this;
}

A::~A() {
    if(!_number) {
        std::cout << "class A destructor: nullptr" << std::endl;
    }
    else {
        std::cout << "class A destructor: " << *_number << std::endl;
        delete _number;
    }
}