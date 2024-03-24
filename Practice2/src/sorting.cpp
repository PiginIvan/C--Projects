#include "sorting.hpp"
#include <iostream>

template<class T>
void sort_arr(std::unique_ptr<T[]>& arr, std::unique_ptr<int>& N) {
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
void sort_arr<char>(std::unique_ptr<char[]>& arr, std::unique_ptr<int>& N) {
	std::cout << "Enter numbers" << std::endl;
	for (int i = 0; i < *N; i++) {
		std::cin >> arr.get();
	}

	int end = *N - 1;
	char x = ' ';
	for (int i = 0; i < end + 1; i++) {
		if ((static_cast<int>(arr[i]) < 65) || (static_cast<int>(arr[i]) > 90 && static_cast<int>(arr[i]) < 97) || (static_cast<int>(arr[i]) > 122)) {
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

template void sort_arr<>(std::unique_ptr<int[]>& arr, std::unique_ptr<int>& N);
template void sort_arr<>(std::unique_ptr<short[]>& arr, std::unique_ptr<int>& N);
template void sort_arr<>(std::unique_ptr<double[]>& arr, std::unique_ptr<int>& N);