#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP

template <class T>
class DynArray {
public:
	int length, count_elem;
	T* data;
	static int arrays_created;

	DynArray();
	DynArray(int size);
	DynArray(const DynArray& other);
	~DynArray();

	int size();
	void append(T num);
	T get(int index);

	DynArray& operator=(const DynArray& other);
	DynArray operator+(const DynArray& other);
	T& operator [](int index);
	DynArray operator<<(int index);
	DynArray operator>>(int index);

};

#endif