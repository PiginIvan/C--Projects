#ifndef CLASSA_HPP
#define CLASSA_HPP

class A {
private:
    int* _number;
public:
    A(int number);

    A(const A& other);
    A(A&& other);

    A& operator=(const A& other);
    A& operator=(A&& other);

    ~A(); 
};

#endif