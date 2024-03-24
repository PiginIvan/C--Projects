#include "DynArray.hpp"

DynArray::DynArray(int size) {
    this->length = size;
    this->data = std::make_unique<double[]>(0);
    this->count_elem = 0;
}

DynArray::~DynArray() {
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
        std::unique_ptr<double[]> arr = std::make_unique<double[]>(this->length);
        for (int i = 0; i < this->count_elem; i++) {
            arr[i] = this->data[i];
        }
        this->data.reset(arr.get());
        this->data[this->count_elem++] = num;
    }
}

double DynArray::get(int index) {
    return this->data[index];
}
