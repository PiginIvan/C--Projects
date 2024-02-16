#include "DynArray.hpp"

template class DynArray<int>;

template<class T>
DynArray<T>::DynArray() { arrays_created++; this->size = 0; };

template<class T>
DynArray<T>::DynArray(int size) { this->size = size; this->data.reserve(size); arrays_created++; }

template<class T>
DynArray<T>::DynArray(const DynArray& other) : data(other.data) { arrays_created++; }

template<class T>
DynArray<T>::~DynArray() { this->size = 0; this->data.clear(); arrays_created--; }

template<class T>
void DynArray<T>::append(T elem) { this->data.push_back(elem); }

template<class T>
T DynArray<T>::pop() { T last = this->data.back(); this->data.pop_back(); return last; }

template<class T>
DynArray<T>& DynArray<T>::operator=(const DynArray& other) { this->size = other.size; this->data = other.data; }

template<class T>
T& DynArray<T>::operator[](int index) { return this->data[index]; }

template<class T>
DynArray<T> DynArray<T>::operator+(const DynArray& other) {
    DynArray ans(this->size + other.size);
    for (int i = 0; i < this->size; i++) ans.append(this->data[i]);
    for (int i = 0; i < other.size; i++) ans.append(other.data[i]);
    return ans;
}

template<class T>
int DynArray<T>::arrays_created = 0;

