#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

class Vector3D {
public:
	double x, y, z;

	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D(const Vector3D& second);

	Vector3D& operator=(const Vector3D& second);
	double operator*(const Vector3D& second);
	Vector3D operator&(const Vector3D& second);

	void Print_vector();

};


#endif