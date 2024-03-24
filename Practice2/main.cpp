#include <iostream>
#include <cctype>
#include <cstring>
#include <memory>

#define TASK2

#ifdef TASK1

void init_arr(std::unique_ptr<int[]>& arr, std::unique_ptr<int>& N) {
	std::cout << "Enter numbers" << std::endl;
	for (int i = 0; i < *N; i++) {
		std::cin >> arr[i];
	}
}

void sort_arr(std::unique_ptr<int[]>& arr, std::unique_ptr<int>& N) {
	for (int i = 0; i < *N; i++) {
		for (int j = 0; j < *N - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void print_arr(std::unique_ptr<int[]>& arr, std::unique_ptr<int>& N) {
	std::cout << std::endl;
	for (int i = 0; i < *N; i++) {
		std::cout << arr[i] << " ";
	}
}

int main() {
	std::unique_ptr<int> N = std::make_unique<int>();
	std::cout << "Enter count of numbers" << std::endl;
	std::cin >> *N;
	std::unique_ptr<int[]> arr = std::make_unique<int[]>(*N);
	sort_arr(arr, N);
	init_arr(arr, N);
	sort_arr(arr, N);
	print_arr(arr, N);
	return 0;
}

#endif

#ifdef TASK2

void sort_arr(std::unique_ptr<int[]>& arr, std::unique_ptr<int>& N) {
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

void sort_arr(std::unique_ptr<short[]>& arr, std::unique_ptr<int>& N) {
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

void sort_arr(std::unique_ptr<double[]>& arr, std::unique_ptr<int>& N) {
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

int main() {
	std::unique_ptr<char[]> str = std::make_unique<char[]>(10);
	std::cout << "Select data type" << std::endl;
	std::cin >> str.get();
	if (!strcmp(str.get(), "int")) {
		std::unique_ptr<int> N = std::make_unique<int>();
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		std::unique_ptr<int[]> arr = std::make_unique<int[]>(*N);
		sort_arr(arr, N);
	}
	else if (!strcmp(str.get(), "short")) {
		std::unique_ptr<int> N = std::make_unique<int>();
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		std::unique_ptr<short[]> arr = std::make_unique<short[]>(*N);
		sort_arr(arr, N);
	}
	else if (!strcmp(str.get(), "double")) {
		std::unique_ptr<int> N = std::make_unique<int>();
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		std::unique_ptr<double[]> arr = std::make_unique<double[]>(*N);
		sort_arr(arr, N);
	}
	return 0;
}

#endif

#ifdef TASK3
#include "sorting.hpp"

int main() {
	std::unique_ptr<char[]> str = std::make_unique<char[]>(10);
	std::cout << "Select data type" << std::endl;
	std::cin >> str.get();
	if (!strcmp(str.get(), "int")) {
		std::unique_ptr<int> N = std::make_unique<int>();
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		std::unique_ptr<int[]> arr = std::make_unique<int[]>(*N);
		sort_arr(arr, N);
	}
	else if (!strcmp(str.get(), "short")) {
		std::unique_ptr<int> N = std::make_unique<int>();
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		std::unique_ptr<short[]> arr = std::make_unique<short[]>(*N);
		sort_arr(arr, N);
	}
	else if (!strcmp(str.get(), "double")) {
		std::unique_ptr<int> N = std::make_unique<int>();
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		std::unique_ptr<double[]> arr = std::make_unique<double[]>(*N);
		sort_arr(arr, N);
	}
	else if (!strcmp(str.get(), "char")) {
		std::unique_ptr<int> N = std::make_unique<int>();
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		std::unique_ptr<char[]> arr = std::make_unique<char[]>(*N);
		sort_arr(arr, N);
	}
	return 0;
}

#endif
