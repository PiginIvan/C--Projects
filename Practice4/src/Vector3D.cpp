#include "Vector3D.hpp"
#include <iostream>

Vector3D::Vector3D() {
    this->x = 0; this->y = 0; this->z = 0;
}

Vector3D::Vector3D(double x, double y, double z) {
    this->x = x; this->y = y; this->z = z;
}

Vector3D::Vector3D(const Vector3D& second) {
    this->x = second.x; this->y = second.y; this->z = second.z;
}

Vector3D& Vector3D::operator=(const Vector3D& second) {
    this->x = second.x; this->y = second.y; this->z = second.z;
    return *this;
}

double Vector3D::operator*(const Vector3D& second) {
    return (this->x * second.x + this->y * second.y + this->z * second.z);
}

Vector3D Vector3D::operator&(const Vector3D& second) {
    return Vector3D(this->y * second.z - this->z * second.y, this->z * second.x - this->x * second.z, this->x * second.y - this->y * second.x);
}

void Vector3D::Print_vector() {
    std::cout << this->x << ' ' << this->y << ' ' << this->z << std::endl;
}