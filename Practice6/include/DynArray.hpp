#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP
#include <vector>

template <class T>
class DynArray {
public:
	std::vector<T> data;
	static int arrays_created;
	int size;

	DynArray();
	DynArray(int size);
	DynArray(const DynArray& other);
	~DynArray();

	void append(T elem);
	T pop();

	DynArray& operator=(const DynArray& other);
	T& operator[](int index);
	DynArray operator+(const DynArray& other);

};

#endif