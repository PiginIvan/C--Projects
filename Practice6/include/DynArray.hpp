#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP
#include <vector>

template <class T>
class DynArray {
private:
	std::vector<T> data;
	int size;

public:
	static int arrays_created;
	
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