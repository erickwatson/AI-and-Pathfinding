#include "stdafx.h"
#include "Vector3.h"
#include <cmath>

Vector3::Vector3() { x = y = z = 0; };

Vector3::Vector3(float i, float j, float k)
{ 
	x = i;
	y = j;
	z = k;
};

float& Vector3::operator[](int index)
{
	return data[index];
}

Vector3 Vector3::operator + (const Vector3& other) const {
	return { x + other.x, y + other.y, z + other.z };
}

Vector3 Vector3::operator - (const Vector3& other) const {
	return { x - other.x, y - other.y, z - other.z };
}

Vector3& Vector3::operator = (const Vector3& other) {
	x = other.x; y = other.y; z = other.z;
	return *this;
}

Vector3& Vector3::operator -= (const Vector3& other) {
	x -= other.x; y -= other.y; z -= other.z;
	return *this;
}

Vector3 Vector3::operator += (const Vector3& other) {
	return { x += other.x, y += other.y, z += other.z };
}

Vector3 Vector3::operator * (float scalar) const {
	return { x * scalar, y * scalar, z * scalar };
}

Vector3& Vector3::operator /= (float scalar) {
	x /= scalar, y /= scalar, z * scalar;
	return *this;
}



Vector3 operator *(float scalar, Vector3 vector)
{
	return vector * scalar;
}

float Vector3::dot(const Vector3& other) {
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other) {
	return Vector3(
				y * other.z - z * other.y,
				z * other.x - x * other.z,
				x * other.y - y * other.x);
}

float Vector3::magnitude() const {	return sqrt(x*x + y * y + z * z);}float Vector3::magnitudeSqr() const {	return (x*x + y * y + z * z);}float Vector3::distance(const Vector3& other) const{
	float diffX = x - other.x;	float diffY = y - other.y;	float diffZ = z - other.z;	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);}void Vector3::normalise() {	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;}Vector3 Vector3::normalised(){
	float mag = sqrt(x*x + y*y + z*z);	return { x/mag, y/mag, z/mag };}