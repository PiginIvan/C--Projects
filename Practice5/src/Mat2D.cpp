#include "Mat2D.hpp"
#include <iostream>

Mat2D::Mat2D() : rows(0), columns(0), data() {}

Mat2D::Mat2D(int m, int n) : rows(m), columns(n), data(m, VecND(n)) {}

Mat2D Mat2D::operator+(const Mat2D& other) {
	Mat2D newMat = Mat2D(this->rows, this->columns);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			newMat[i][j] = data[i][j] + other[i][j];
		}
	}
	return newMat;
}

VecND Mat2D::getRow(int row) {
	return data[row];
}

VecND Mat2D::getCol(int col) {
	VecND newVec = VecND(this->rows);
	for (int i = 0; i < this->rows; i++) {
		newVec[i] = data[i][col];
	}
	return newVec;
}

const VecND Mat2D::getCol(int col) const {
	VecND newVec = VecND(this->rows);
	for (int i = 0; i < this->rows; i++) {
		newVec[i] = data[i][col];
	}
	return newVec;
}

Mat2D Mat2D::operator*(const Mat2D& other) {
	Mat2D newMat = Mat2D(this->rows, other.columns);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			VecND curRow = this->getRow(i);
			VecND curCol = other.getCol(j);
			int ans = 0;
			for (int k = 0; k < this->rows; k++) {
				ans += curRow[k] * curCol[k];
			}
			newMat[i][j] = ans;
		}
	}
	return newMat;
}

VecND Mat2D::operator*(const VecND& other) {
	VecND newVec(this->rows);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			newVec[i] += data[i][j] * other[j];
		}
	}
	return newVec;
}

VecND& Mat2D::operator[](int index) {
	return data[index];
}

const VecND& Mat2D::operator[](int index) const {
	return data[index];
}

void Mat2D::print_matrix() {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Mat2D Mat2D::transpose() {
	Mat2D newMat = Mat2D(this->rows, this->columns);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			newMat[i][j] = data[j][i];
		}
	}
	return newMat;
}

int Mat2D::getDeterminant() {
	if (this->rows == 1 && this->columns == 1) {
		return data[0][0];
	}
	if (this->rows == 2 && this->columns == 2) {
		return ((data[0][0] * data[1][1]) - (data[0][1] * data[1][0]));
	}
	return 0;
}
