#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP
#include <memory>

class DynArray {
private:
	int length;
	std::unique_ptr<double[]> data;
	int count_elem;

public:
	DynArray(int size);
	~DynArray();

	int size();
	void append(double num);
	double get(int index);

};

#endif