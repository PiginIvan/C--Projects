#include "sorting.hpp"
#include <iostream>

template<class T>
void sort_arr(T* arr, int* N) {
	std::cout << "Enter numbers" << std::endl;
	for (int i = 0; i < *N; i++) {
		std::cin >> arr[i];
	}


	for (int i = 0; i < *N; i++) {
		for (int j = 0; j < *N - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}

	std::cout << std::endl;
	for (int i = 0; i < *N; i++) {
		std::cout << arr[i] << " ";
	}
}

template<>
void sort_arr<char>(char* arr, int* N) {
	std::cout << "Enter numbers" << std::endl;
	for (int i = 0; i < *N; i++) {
		std::cin >> arr[i];
	}

	int end = *N - 1;
	char x = ' ';
	for (int i = 0; i < end + 1; i++) {
		if (((int)arr[i] < 65) || ((int)arr[i] > 90 && (int)arr[i] < 97) || ((int)arr[i] > 122)) {
			arr[i] = ' '; std::swap(arr[i], arr[end--]); i--;
		}
	}

	for (int i = 0; i < end + 1; i++) {
		for (int j = 0; j < end - i; j++) {
			if (arr[j] != ' ' && tolower(arr[j]) > tolower(arr[j + 1])) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
	for (int i = 0; i < *N; i++) {
		std::cout << arr[i];
	}

}

template void sort_arr<>(int*, int*);
template void sort_arr<>(short*, int*);
template void sort_arr<>(double*, int*);