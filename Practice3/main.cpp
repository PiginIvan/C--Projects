#include <iostream>

#define TASK2

#ifdef TASK1
#include "DynArray.hpp"

int main() {
	DynArray arr(10);
	arr.append(1.0);

	for (int i = 0; i < 15; i++) {
		arr.append(i + 0.0);
	}

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr.get(i) << " ";
	}

	std::cout << std::endl;
    return 0;
}

#endif

#ifdef TASK2
#include "MyStack.hpp"

int main() {
	MyStack stack(10);
	stack.isEmpty();

	for (int i = 0; i < 12; i++) {
		stack.push(i);
	}

	stack.isEmpty();

	int length = stack.count();
	for (int i = 0; i < length + 1; i++) {
		std::cout << stack.pop() << std::endl;
	}
    return 0;
}

#endif
