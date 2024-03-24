#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP
#include <memory>

template <class T>
class DynArray {
private:
	int length, count_elem;
	std::unique_ptr<T[]> data;

public:
	static int arrays_created;

	DynArray();
	DynArray(int size);
	DynArray(const DynArray& other);
	~DynArray();

	int size();
	void append(T num);
	int get_length();
	T get(int index);

	DynArray& operator=(const DynArray& other);
	DynArray operator+(const DynArray& other);
	T& operator [](int index);
	DynArray operator<<(int index);
	DynArray operator>>(int index);

};

#endif