#include <iostream>

#define TASK2

#ifdef TASK1
#include "Vector3D.hpp"

int main() {
	Vector3D vec1(1, 2, 3), vec2(5, 6, 7.5);

	double dot_prod = vec1 * vec2;
	Vector3D cross_prod = vec1 & vec2;

	std::cout << dot_prod << std::endl;
	cross_prod.Print_vector();

	return 0;
}

#endif

#ifdef TASK2
#include "DynArray.hpp"

int main() {
	DynArray<float> arr1(10);
	DynArray<float> arr2(15);

	for (int i = 0; i < arr1.size(); i++) {
		arr1[i] = (i + 0.5);
	}

	for (int i = 0; i < arr2.size(); i++) {
		arr2[i] = (i + 0.5);
	}

	std::cout << "Appeal to data of class by operator []" << std::endl;
	for (int i = 0; i < arr1.get_length(); i++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Cur count arrays: " << DynArray<float>::arrays_created << std::endl;

	std::cout << "Array received by operator + of 2 other arrays" << std::endl;
	DynArray<float> arr3 = arr1 + arr2;
	for (int i = 0; i < arr3.get_length(); i++) {
		std::cout << arr3[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Left rotate by 3 elements" << std::endl;
	DynArray<float> arr4 = arr1.operator>>(3);
	for (int i = 0; i < arr4.get_length(); i++) {
		std::cout << arr4[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Right rotate by 4 elements" << std::endl;
	DynArray<float> arr5 = arr1.operator<<(4);
	for (int i = 0; i < arr5.get_length(); i++) {
		std::cout << arr5[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

#endif
