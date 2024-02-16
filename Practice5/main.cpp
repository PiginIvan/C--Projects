#include <iostream>
#include "Mat2D.hpp"
#include "VecND.hpp"

int main() {

	Mat2D first(2, 2);
	first[0][0] = 5; first[0][1] = 5; first[1][0] = 5; first[1][1] = 5;
	std::cout << "Matrix 1" << std::endl;
	first.print_matrix();

	Mat2D second(2, 2);
	second[0][0] = 1; second[0][1] = 2; second[1][0] = 3; second[1][1] = 4;
	std::cout << "Matrix 2" << std::endl;
	second.print_matrix();
	
	Mat2D sum = first + second;
	std::cout << "Sum of matrices 1 and 2" << std::endl;
	sum.print_matrix();

	Mat2D mul = first * second;
	std::cout << "Mul of matrices 1 and 2" << std::endl;
	mul.print_matrix();

	Mat2D transpose = second.transpose();
	std::cout << "Transposed matrix 2" << std::endl;
	transpose.print_matrix();
	std::cout << "Determinant of matrix 2" << std::endl;
	std::cout << second.getDeterminant() << std::endl;

	VecND vector;
	vector.push_back(3); vector.push_back(4);
	std::cout << "Vector 1" << std::endl;
	vector.print_vec();
	std::cout << "Mul of matrix 2 and vector 1" << std::endl;
	(second * vector).print_vec();

	return 0;
}