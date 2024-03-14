#include "DynArray.hpp"
#include <iostream>

template<class T>
DynArray<T>::DynArray() {
	this-> length = 0; this->count_elem = 0;
	data = nullptr;
}

template<class T>
DynArray<T>::DynArray(int size) {
	this->length = size;
	this->count_elem = 0;
	this->data = new T[size];
	arrays_created++;
}

template<class T>
DynArray<T>::~DynArray() {
	delete[] this->data;
	arrays_created--;
}

template<class T>
DynArray<T>::DynArray(const DynArray& other) {
	this->length = other.length;
	this->data = new T[this->length];
	for (int i = 0; i < this->length; i++) {
		this->data[i] = other.data[i];
	}
	arrays_created++;
}

template<class T>
int DynArray<T>::size() {
	return this->length;
}

template<class T>
void DynArray<T>::append(T num) {
	if (this->count_elem != this->length) {
		this->data[this->count_elem++] = num;
	}
	else {
		this->length *= 2;
		T* arr = new T[this->length];
		for (int i = 0; i < this->count_elem; i++) {
			arr[i] = this->data[i];
		}
		delete[] this->data;
		this->data = arr;
		this->data[this->count_elem++] = num;
	}
}

template<class T>
int DynArray<T>::get_length() { return length; }

template<class T>
T DynArray<T>::get(int index) {
	return this->data[index];
}

template<class T>
DynArray<T>& DynArray<T>::operator=(const DynArray& other) {
	delete[] this->data;
	this->length = other.length;
	this->data = new T[this->length];
	for (int i = 0; i < this->length; i++) {
		this->data[i] = other.data[i];
	}
	return *this;
}

template<class T>
T& DynArray<T>::operator [](int index) {
	return this->data[index];
}

template<class T>
DynArray<T> DynArray<T>::operator+(const DynArray& other) {
	DynArray<T> tmp;
	tmp.length = this->length + other.length;
	tmp.data = new T[tmp.length];
	int i = 0;
	for (int i = 0, j = 0; i < tmp.length; i++) {
		if (i < this->length) {
			tmp.data[i] = this->data[i];
		}
		else {
			tmp.data[i] = other.data[j++];
		}
	}
	return tmp;
}

template<class T>
DynArray<T> DynArray<T>::operator<<(int index) {
	DynArray<T> tmp(this->length);
	for (int i = 0; i < this->length; i++) {
		tmp.data[i] = this->data[i];
	}

	if (index < 0 || index >= this->length) {
		return tmp;
	}

	for (int i = 0; i < index; i++) {
		int first = tmp.data[0];
		for (int i = 0; i < tmp.length -1; i++) {
			tmp.data[i] = tmp.data[i + 1];
		}

		tmp.data[tmp.length - 1] = first;
	}

	return tmp;
}

template<class T>
DynArray<T> DynArray<T>::operator>>(int index) {
	DynArray<T> tmp(this->length);
	for (int i = 0; i < this->length; i++) {
		tmp.data[i] = this->data[i];
	}

	if (index < 0 || index >= this->length) {
		return tmp;
	}

	for (int i = 0; i < index; i++) {
		int last = tmp.data[tmp.length - 1];
		for (int i = this->length - 2; i >= 0; i--) {
			tmp.data[i + 1] = tmp.data[i];
		}

		tmp.data[0] = last;
	}

	return tmp;
}

template <class T>
int DynArray<T>::arrays_created = 0;

template class DynArray<int>;
template class DynArray<float>;