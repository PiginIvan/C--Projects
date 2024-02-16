#include "DynArray.hpp"

DynArray::DynArray(int size) {
    this->length = size;
    this->data = new double[size];
    this->count_elem = 0;
}

DynArray::~DynArray() {
    delete[] this->data;
    this->length = 0;
    this->count_elem = 0;
}

int DynArray::size() {
    return this->count_elem;
}

void DynArray::append(double num) {
    if (this->count_elem != this->length) {
        this->data[this->count_elem++] = num;
    }
    else {
        this->length *= 2;
        double* arr = new double[this->length];
        for (int i = 0; i < this->count_elem; i++) {
            arr[i] = this->data[i];
        }
        delete[] this->data;
        this->data = arr;
        this->data[this->count_elem++] = num;
    }
}

double DynArray::get(int index) {
    for (int i = 0; i < this->length; i++) {
        if (i == index) {
            return this->data[i];
        }
    }
}
