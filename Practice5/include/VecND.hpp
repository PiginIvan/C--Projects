#ifndef VECND_HPP
#define VECND_HPP
#include <vector>
#include "iostream"

class VecND {
private:
	std::vector<int> data;

public:
	VecND();
	VecND(int size);
	VecND(const VecND& other);
	
	int& operator[](int index);
	const int& operator[](int index) const;
	VecND& operator=(const VecND& other);

	void push_back(int elem);
	void print_vec();
};

#endif