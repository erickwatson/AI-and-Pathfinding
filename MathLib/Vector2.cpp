#include "stdafx.h"
#include "Vector2.h"
#include <cmath>

Vector2::Vector2() { x = y = 0; };

Vector2::Vector2(float i, float j)
{
	x = i;
	y = j;
};

float& Vector2::operator[](int index)
{
	return data[index];
}

Vector2 Vector2::operator + (const Vector2& other) const {
	return { x + other.x, y + other.y };
}

Vector2 Vector2::operator - (const Vector2& other) const {
	return { x - other.x, y - other.y };
}

Vector2& Vector2::operator -= (const Vector2& other) {
	x -= other.x; y -= other.y;
	return *this;
}

Vector2& Vector2::operator += (const Vector2& other) {
	x += other.x; y += other.y;
	return *this;
}

Vector2 Vector2::operator * (float scalar) const {
	return { x * scalar, y * scalar };
}

Vector2& Vector2::operator /= (float scalar) {
	x /= scalar, y /= scalar;
	return *this;
}

Vector2& Vector2::operator = (const Vector2& other) {
	x = other.x; y = other.y;
	return *this;
}

Vector2 operator *(float scalar, Vector2 vector)
{
	return vector * scalar;
}

float Vector2::dot(const Vector2& other) {
	return x * other.x + y * other.y;
}

float Vector2::cross(const Vector2& other) {
	return x * other.y - y * other.x;
}

float Vector2::magnitude() const {	return sqrt(x*x + y * y);}float Vector2::magnitudeSqr() const {	return (x*x + y * y);}float Vector2::distance(const Vector2& other) const {
	float diffX = x - other.x;	float diffY = y - other.y;	return sqrt(diffX * diffX + diffY * diffY);}void Vector2::normalise() {	float mag = magnitude();
	x /= mag;
	y /= mag;
}Vector2 Vector2::normalised() {
	float mag = sqrt(x*x + y * y);	return { x / mag, y / mag, };}