#include "stdafx.h"
#include "Vector4.h"
#include <cmath>


Vector4::Vector4() {x = y = z = w = 0; };

Vector4::Vector4(float i, float j, float k, float l)
{
	x = i;
	y = j;
	z = k;
	w = l;
};

float Vector4::operator[](int index) const
{
	return data[index];
}
// Addition
Vector4 Vector4::operator + (const Vector4& other) const {
	return { x + other.x, y + other.y, z + other.z, w + other.w };
}
// Subtraction
Vector4 Vector4::operator - (const Vector4& other) const {
	return { x - other.x, y - other.y, z - other.z, w - other.w };
}

Vector4& Vector4::operator += (const Vector4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Vector4& Vector4::operator -= (const Vector4& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

// Equals
Vector4& Vector4::operator = (const Vector4& other) {
	x = other.x; y = other.y; z = other.z; w = other.w;
	return *this;
}

//Multiply
Vector4 Vector4::operator * (float scalar) const {
	return { x * scalar, y * scalar, z * scalar, w * scalar };
}

Vector4& Vector4::operator *= (float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}

Vector4& Vector4::operator /= (float scalar) {
	x /= scalar, y /= scalar, z * scalar, w /= scalar;
	return *this;
}


Vector4 operator *(float scalar, Vector4 vector)
{
	return vector * scalar;
}

float Vector4::dot(const Vector4& other) {
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

Vector4 Vector4::cross(const Vector4& other) {
	return Vector4(
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x,
		w * other.w - w * other.w
		);
}

float Vector4::magnitude() const {	return sqrt(x*x + y*y + z*z + w*w);}float Vector4::magnitudeSqr() const {	return (x*x + y*y + z*z + w*w);}float Vector4::distance(const Vector4& other) const {
	float diffX = x - other.x;	float diffY = y - other.y;	float diffZ = z - other.z;	float diffW = w - other.w;	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ + diffW * diffW);}void Vector4::normalise() {	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;	w /= mag;}Vector4 Vector4::normalised() {
	float mag = sqrt(x*x + y*y + z*z + w*w);	return { x / mag, y / mag, z / mag, w / mag };}