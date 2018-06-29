#pragma once
#include "Vector4.h"

class Matrix4
{
public:

	union {
		struct {
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 translation;
		};
		Vector4 axis[4];
		float data[4][4];
	};

	Matrix4();
	
	Matrix4(float e0, float e1, float e2, float e3,
			float e4, float e5,	float e6, float e7,
			float e8, float e9, float e10, float e11,
			float e12, float e13, float e14, float e15)
	{
		// WUUUTTTTT
		
		data[0][0] = e0;
		data[0][1] = e1;
		data[0][2] = e2;
		data[0][3] = e3;

		data[1][0] = e4;
		data[1][1] = e5;
		data[1][2] = e6;
		data[1][3] = e7;

		data[2][0] = e8;
		data[2][1] = e9;
		data[2][2] = e10;
		data[2][3] = e11;

		data[3][0] = e12;
		data[3][1] = e13;
		data[3][2] = e14;
		data[3][3] = e15;
	};
	static const Matrix4 identity;
	~Matrix4();

	operator float* () {
		return &data[0][0];
	}

	operator const float* () const {
		return &data[0][0];
	}

	Vector4& operator [] (int index);

	const Vector4& operator [] (int index) const;



	Matrix4 operator * (const Matrix4& other) const;

	Vector4 operator * (const Vector4& v) const;

	Matrix4& operator = (const Matrix4& other);

	Matrix4 transposed() const;

	void setScaled(float x, float y, float z, float w);

	void setScaled(const Vector4& v);

	void scale(float x, float y, float z, float w);

	void scale(const Vector4& v);

	void setRotateX(float radians);

	void setRotateY(float radians);

	void setRotateZ(float radians);

	void rotateX(float radians);

	void rotateY(float radians);

	void rotateZ(float radians);

	void translate(float x, float y, float z);


};

