#include "stdafx.h"
#include "Matrix3.h"
#include <cmath>

/*

Place inside main cpp

Matrix3 m;

// Assign a vector to X-axis
m[0] = Vector3(1, 0, 0);

// Assign a value to Z-axis.y if
// Vector3 has sub-script access
m[2][1] = 99;

*/

Vector3& Matrix3::operator [] (int index) {
	return axis[index];
};

const Vector3& Matrix3::operator [] (int index) const {
	return axis[index];
};

Matrix3 Matrix3::operator * (const Matrix3& other) const {

	Matrix3 result;

	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			result.data[c][r] = data[0][r] * other.data[c][0] +
								data[1][r] * other.data[c][1] +
								data[2][r] * other.data[c][2];
		}
	}

	return result;
};

Vector3 Matrix3::operator * (const Vector3& v) const {

	Vector3 result;

	for (int r = 0; r < 3; ++r) {
		result[r] = data[0][r] * v[0] +
					data[1][r] * v[1] +
					data[2][r] * v[2];
	}

	return result;

};

Matrix3& Matrix3::operator = (const Matrix3& other) {

	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			data[c][r] = other.data[c][r];
		}
	}
	return *this;
}

Matrix3 Matrix3::transposed() const {

	Matrix3 result;

	// flip row and column
	for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 3; ++c)
			result.data[r][c] = data[c][r];

	return result;
};

const Matrix3 Matrix3::identity = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);

void Matrix3::setScaled(float x, float y, float z) {
	
	// set scale of each axis
	xAxis = { x, 0, 0 };
	yAxis = { 0, y, 0 };
	zAxis = { 0, 0, z };

};

void Matrix3::setScaled(const Vector3& v) {

	// set scale of each axis
	xAxis = { v.x, 0, 0 };
	yAxis = { 0, v.y, 0 };
	zAxis = { 0, 0, v.z };
};

void Matrix3::scale(float x, float y, float z) {
	Matrix3 m;
	m.setScaled(x, y, z);

	*this = *this * m;
};

void Matrix3::scale(const Vector3& v) {
	Matrix3 m;
	m.setScaled(v.x, v.y, v.z);

	*this = *this * m;
}

void Matrix3::translate(float x, float y) {
	translation += Vector3(x, y, 0);
}

void Matrix3::setRotateX(float radians) {
	
	// leave X axis and elements unchanged
	xAxis = { 1,			0,				0 };
	yAxis = { 0, cosf(radians), sinf(radians) };
	zAxis = { 0, -sinf(radians), cosf(radians) };

	//might be incorrect above, could be this
	/*
	xAxis = { 1,			0,				0 };
	yAxis = { 0, cosf(radians), -sinf(radians) };
	zAxis = { 0, sinf(radians), cosf(radians) };
	*/
}

void Matrix3::setRotateY(float radians) {

	// leave X axis and elements unchanged
	xAxis = { cosf(radians), 0, -sinf(radians) };
	yAxis = {			  0, 1,				0 };
	zAxis = { sinf(radians), 0, cosf(radians) };
}

void Matrix3::setRotateZ(float radians) {

	// leave X axis and elements unchanged
	xAxis = { cosf(radians), sinf(radians), 0 };
	yAxis = { -sinf(radians), cosf(radians), 0 };
	zAxis = {				0,		0,		1 };
}

void Matrix3::rotateX(float radians) {
	Matrix3 m;
	m.setRotateX(radians);

	*this = *this * m;
}

void Matrix3::rotateY(float radians) {
	Matrix3 m;
	m.setRotateY(radians);

	*this = *this * m;
}

void Matrix3::rotateZ(float radians) {
	Matrix3 m;
	m.setRotateZ(radians);

	*this = *this * m;
}

void Matrix3::setEuler(float pitch, float yaw, float roll) {

	Matrix3 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);

	// Combine rotations in a specific order
	*this = z * y * x;

}