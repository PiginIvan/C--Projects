#define TASK2

#ifdef TASK1
#include <iostream>
#include <vector>

void delete_zero(std::vector<int>& data) {	
	for (auto it = data.begin(); it != data.end();) {
		if (*it == 0) {
			it = data.erase(it);
		}
		else {
			++it;
		}
	}
	data.shrink_to_fit();
}

int main() {
	std::vector<int> data = { 1, 2, 3, 0, 6, 7, 0, 5, 10 };
	
	std::cout << "Initial vector" << std::endl;
	for (auto it = data.begin(); it != data.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Vector size: " << data.size() << " " << "Vector capacity: " << data.capacity() << std::endl;

	delete_zero(data);

	std::cout << "Fixed vector" << std::endl;
	for (auto it = data.begin(); it != data.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Vector size: " << data.size() << " " << "Vector capacity: " << data.capacity() << std::endl;

	return 0;
}
#endif

#ifdef TASK2
#include <iostream>
#include "LinkedList.hpp"

int main() {

	LinkedList<int> data;
    data.push_front(0);

	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	
	data.push_front(0);
	data.push_front(4);

	data.print_list();

	std::cout << data.find(5) << " " << data.find(4) << std::endl;

    data.pop_back();
	data.pop_back();

	data.print_list();
	
	data.pop_front();
	data.pop_front();

	data.print_list();

	std::string s = "abcd";
	LinkedList<char> word(s);
	word.push_back('f');
	word.print_list();

	data.print_list_iters();


	return 0;
}

#endif