#pragma once
#include "Vector2.h"

class Matrix2
{
public:

	union {
		struct {
			Vector2 xAxis;
			Vector2 yAxis;
			
		};
		Vector2 axis[2];
		float data[2][2];
	};
	static const Matrix2 identity;

	Matrix2() {};
	Matrix2(float e0, float e1,
			float e2, float e3)
	{
		data[0][0] = e0;
		data[0][1] = e1;
		
		data[1][0] = e2;
		data[1][1] = e3;

	};
	~Matrix2() {};

	operator float* () {
		return &data[0][0];
	}

	operator const float* () const {
		return &data[0][0];
	}

	Vector2& operator [] (int index);

	const Vector2& operator [] (int index) const;

	Matrix2 operator * (const Matrix2& other) const;

	Vector2 operator * (const Vector2& v) const;

	Matrix2& operator = (const Matrix2& other);

	Matrix2 transposed() const;

	void setScaled(float x, float y);

	void setScaled(const Vector2& v);

	void scale(float x, float y);

	void scale(const Vector2& v);
	
	void setRotate(float radians);
	
	void rotate(float radians);
	
};

