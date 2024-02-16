#include <VecND.hpp>

VecND::VecND() : data(0) {}

VecND::VecND(int size) : data(size) {}

VecND::VecND(const VecND& other) : data(other.data) {}

void VecND::push_back(int elem) { data.push_back(elem); }

void VecND::print_vec() {
	for (int i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

int& VecND::operator[](int index) { return data[index]; }

const int& VecND::operator[](int index) const { return data[index]; }

VecND& VecND::operator=(const VecND& other) {
	this->data.resize(other.data.size());
	this->data = other.data;
	return *this;
}
