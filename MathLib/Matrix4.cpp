#include "stdafx.h"
#include "Matrix4.h"
#include <cmath>


Matrix4::Matrix4()
{
}


Matrix4::~Matrix4()
{
}


Vector4& Matrix4::operator [] (int index) {
	return axis[index];
};

const Vector4& Matrix4::operator [] (int index) const {
	return axis[index];
};





Matrix4 Matrix4::operator * (const Matrix4& other) const {

	Matrix4 result;

	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			result.data[c][r] = 
				data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2] +
				data[3][r] * other.data[c][3];
		}
	}

	return result;
};

Vector4 Matrix4::operator * (const Vector4& v) const {

	Vector4 result;

	for (int r = 0; r < 4; ++r) {
		result.data[r] = data[0][r] * v[0] +
						 data[1][r] * v[1] +
						 data[2][r] * v[2] +
						 data[3][r] * v[3];
	}

	return result;

};



Matrix4& Matrix4::operator = (const Matrix4& other) {

	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			data[c][r] = other.data[c][r];
		}
	}
	return *this;
}

Matrix4 Matrix4::transposed() const {

	Matrix4 result;

	// flip row and column
	for (int r = 0; r < 4; ++r)
		for (int c = 0; c < 4; ++c)
			result.data[r][c] = data[c][r];

	return result;
};

// Create a static const identity matrix
const Matrix4 Matrix4::identity = Matrix4(1, 0, 0, 0,
										  0, 1, 0, 0,
										  0, 0, 1, 0,
										  0, 0, 0, 1);

void Matrix4::setScaled(float x, float y, float z, float w) {

	// set scale of each axis
	xAxis =		  { x, 0, 0, 0 };
	yAxis =		  { 0, y, 0, 0 };
	zAxis =		  { 0, 0, z, 0 };
	translation = { 0, 0, 0, w };

};

void Matrix4::setScaled(const Vector4& v) {

	// set scale of each axis
	xAxis =		  { v.x, 0, 0, 0 };
	yAxis =		  { 0, v.y, 0, 0 };
	zAxis =		  { 0, 0, v.z, 0 };
	translation = { 0, 0, 0, v.w };
};

void Matrix4::scale(float x, float y, float z, float w) {
	Matrix4 m;
	m.setScaled(x, y, z, w);

	*this = *this * m;
};

void Matrix4::scale(const Vector4& v) {
	Matrix4 m;
	m.setScaled(v.x, v.y, v.z, v.w);

	*this = *this * m;
}

void Matrix4::setRotateX(float radians) {

	// leave X axis and elements unchanged
	xAxis = { 1,			0,				0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians), 0 };
	zAxis = { 0, -sinf(radians), cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };

}

void Matrix4::setRotateY(float radians) {

	// leave X axis and elements unchanged
	xAxis = { cosf(radians), 0, -sinf(radians), 0 };
	yAxis = { 0, 1,				0, 0};
	zAxis = { sinf(radians), 0, cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::setRotateZ(float radians) {

	// leave X axis and elements unchanged
	xAxis = { cosf(radians), sinf(radians), 0, 0 };
	yAxis = { -sinf(radians), cosf(radians), 0, 0 };
	zAxis = { 0,		0,		1, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::rotateX(float radians) {
	Matrix4 m;
	m.setRotateX(radians);

	*this = *this * m;
}

void Matrix4::rotateY(float radians) {
	Matrix4 m;
	m.setRotateY(radians);

	*this = *this * m;
}

void Matrix4::rotateZ(float radians) {
	Matrix4 m;
	m.setRotateZ(radians);

	*this = *this * m;
}

void Matrix4::translate(float x, float y, float z) {
	// Apply vector offset
	translation += Vector4(x, y, z, 0);
}