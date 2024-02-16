#ifndef MAT2D_HPP
#define MAT2D_HPP
#include <vector>
#include "VecND.hpp"

class Mat2D {
public:
	int rows, columns;
	std::vector<VecND> data;

	Mat2D();
	Mat2D(int m, int n);
	
	Mat2D operator+(const Mat2D& other);
	Mat2D operator*(const Mat2D& other);
	VecND operator*(const VecND& other);
	VecND& operator[](int index);
	const VecND& operator[](int index) const;

	VecND getRow(int row);
	VecND getCol(int col);
	const VecND getCol(int col) const;
	void print_matrix();
	Mat2D transpose();
	int getDeterminant();
};

#endif
