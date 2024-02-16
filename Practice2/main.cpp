#include <iostream>
#include <cctype>
#include <cstring>

#define TASK3

#ifdef TASK1

void init_arr(int* arr, int* N) {
	std::cout << "Enter numbers" << std::endl;
	for (int i = 0; i < *N; i++) {
		std::cin >> arr[i];
	}
}

void sort_arr(int* arr, int* N) {
	for (int i = 0; i < *N; i++) {
		for (int j = 0; j < *N - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void print_arr(int* arr, int* N) {
	std::cout << std::endl;
	for (int i = 0; i < *N; i++) {
		std::cout << arr[i] << " ";
	}
}

int main() {
	int* N = new int;
	std::cout << "Enter count of numbers" << std::endl;
	std::cin >> *N;
	int* arr = new int[*N];
	init_arr(arr, N);
	sort_arr(arr, N);
	print_arr(arr, N);
	delete N;
	delete[] arr;
	return 0;
}

#endif

#ifdef TASK2

void sort_arr(int* arr, int* N) {
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

void sort_arr(short* arr, int* N) {
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

void sort_arr(double* arr, int* N) {
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
	char* str = new char[10];
	std::cout << "Select data type" << std::endl;
	std::cin >> str;
	if (!strcmp(str, "int")) {
		int* N = new int;
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		int* arr = new int[*N];
		sort_arr(arr, N);
		delete N;
		delete[] arr;
	}
	else if (!strcmp(str, "short")) {
		int* N = new int;
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		int* arr = new int[*N];
		sort_arr(arr, N);
		delete N;
		delete[] arr;
	}
	else if (!strcmp(str, "double")) {
		int* N = new int;
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		double* arr = new double[*N];
		sort_arr(arr, N);
		delete N;
		delete[] arr;
	}
	delete[] str;
	return 0;
}

#endif

#ifdef TASK3
#include "sorting.hpp"

int main() {
	char* str = new char[10];
	std::cout << "Select data type" << std::endl;
	std::cin >> str;
	if (!strcmp(str, "int")) {
		int* N = new int;
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		int* arr = new int[*N];
		sort_arr(arr, N);
		delete N;
		delete[] arr;
	}
	else if (!strcmp(str, "short")) {
		int* N = new int;
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		int* arr = new int[*N];
		sort_arr(arr, N);
		delete N;
		delete[] arr;
	}
	else if (!strcmp(str, "double")) {
		int* N = new int;
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		double* arr = new double[*N];
		sort_arr(arr, N);
		delete N;
		delete[] arr;
	}
	else if (!strcmp(str, "char")) {
		int* N = new int;
		std::cout << "Enter count of numbers" << std::endl;
		std::cin >> *N;
		char* arr = new char[*N];
		sort_arr(arr, N);
		delete N;
		delete[] arr;
	}
	delete[] str;
	return 0;
}

#endif
