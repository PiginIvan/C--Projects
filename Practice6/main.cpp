#include <iostream>
#include <vector>

#define TASK1

#ifdef TASK1
#include "DynArray.hpp"

int main() {
	DynArray<int> a(10);
	for (int i = 0; i < 10; i++) a.append(i);

	std::cout << DynArray<int>::arrays_created;
	std::cout << std::endl;

	DynArray<int> b(5);
	for (int i = 4; i >= 0; i--) b.append(i);
	
    DynArray<int> c = a + b;
	for (int i = 0; i < 15; i++) std::cout << c.pop() << " ";
	std::cout << std::endl;
	std::cout << DynArray<int>::arrays_created;

	return 0;
}
#endif

#ifdef TASK2
#include "Queue.hpp"

int main() {
	Queue a(10);
	for (int i = 0; i < 10; i++) a.enqueue(i);
	for (int i = 0; i < 10; i++) std::cout << a[i] << " ";
	std::cout << std::endl;

	std::cout << a.dequeue() << " " << a.dequeue();
	std::cout << std::endl;

	std::cout << a.front() << " " << a.back() << " ";
	return 0;
}
#endif
