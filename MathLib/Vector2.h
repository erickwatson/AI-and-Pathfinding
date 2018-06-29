#pragma once
#include "stdafx.h"

class Vector2 {
public: 
	union {
		struct {
			float x, y;
		};
		float data[2];
	};

	Vector2();
	Vector2(float, float);

	// Changed this for Matrix2 to work
	// Was originally:
	// float operator [] (int index) const;
	float& operator [] (int index);

	operator float* () {
		return &data[0];
	}

	operator const float* () const {
		return &data[0];
	}

	Vector2 operator + (const Vector2& other) const;

	Vector2 operator - (const Vector2& other) const;

	Vector2& operator -= (const Vector2& other);

	Vector2& operator += (const Vector2& other);

	Vector2 operator * (float scalar) const;

	Vector2& operator /= (float scalar);

	Vector2& operator = (const Vector2& other);

	float dot(const Vector2& other);

	float cross(const Vector2& other);

	float magnitude() const;	float magnitudeSqr() const;
	float distance(const Vector2& other) const;

	void normalise();

	Vector2 normalised();

};

Vector2 operator *(float scalar, Vector2 vector);