#include "stdafx.h"
#include "Matrix2.h"
#include <cmath>


Vector2& Matrix2::operator [] (int index) {
	return axis[index];
};

const Vector2& Matrix2::operator [] (int index) const {
	return axis[index];
};

Matrix2 Matrix2::operator * (const Matrix2& other) const {

	Matrix2 result;

	for (int r = 0; r < 2; ++r) {
		for (int c = 0; c < 2; ++c) {
			result.data[c][r] = 
				data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] ;
		}
	}

	return result;
};

Vector2 Matrix2::operator * (const Vector2& v) const {

	Vector2 result;

	for (int r = 0; r < 2; ++r) {
		result[r] = 
			data[0][r] * v[0] +
			data[1][r] * v[1] ;
	}

	return result;

};

Matrix2& Matrix2::operator = (const Matrix2& other) {

	for (int r = 0; r < 2; ++r) {
		for (int c = 0; c < 2; ++c) {
			data[c][r] = other.data[c][r];
		}
	}
	return *this;
}

Matrix2 Matrix2::transposed() const {

	Matrix2 result;

	// flip row and column
	for (int r = 0; r < 2; ++r)
		for (int c = 0; c < 2; ++c)
			result.data[r][c] = data[c][r];

	return result;
};

const Matrix2 Matrix2::identity = Matrix2 (1, 0, 0, 1 );

void Matrix2::setScaled(float x, float y) {

	// set scale of each axis
	xAxis = { x, 0, };
	yAxis = { 0, y, };
	

};

void Matrix2::setScaled(const Vector2& v) {

	// set scale of each axis
	xAxis = { v.x, 0 };
	yAxis = { 0, v.y };
	
};

void Matrix2::scale(float x, float y) {
	Matrix2 m;
	m.setScaled(x, y);

	*this = *this * m;
};

void Matrix2::scale(const Vector2& v) {
	Matrix2 m;
	m.setScaled(v.x, v.y);

	*this = *this * m;
}

void Matrix2::setRotate(float radians) {

	// leave X axis and elements unchanged
	xAxis = { cosf(radians), sinf(radians) };
	yAxis = { -sinf(radians), cosf(radians) };
	
}

void Matrix2::rotate(float radians) {
	Matrix2 m;
	m.setRotate(radians);

	*this = *this * m;
}