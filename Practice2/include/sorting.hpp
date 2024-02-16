#ifndef SORTING_HPP
#define SORTING_HPP

template<class T>
void sort_arr(T* arr, int* N);

template<>
void sort_arr<char>(char* arr, int* N);

#endif