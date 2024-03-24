#ifndef SORTING_HPP
#define SORTING_HPP
#include <memory>

template<class T>
void sort_arr(std::unique_ptr<T[]>& arr, std::unique_ptr<int>& N);

template<>
void sort_arr<char>(std::unique_ptr<char[]>& arr, std::unique_ptr<int>& N);

#endif