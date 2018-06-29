#pragma once
#include "Vector3.h"
class Matrix3
{
public:

	union {
		struct {
			Vector3 xAxis;
			Vector3 yAxis;
			union {
				Vector3 zAxis;
				Vector3 translation;
			};
		};
		Vector3 axis[3];
		float data[3][3];
	};
	static const Matrix3 identity;

	Matrix3() {};
	Matrix3(float e0, float e1, float e2,
			float e3, float e4, float e5,
			float e6, float e7, float e8) 
	{
		data[0][0] = e0;
		data[0][1] = e1;
		data[0][2] = e2;

		data[1][0] = e3;
		data[1][1] = e4;
		data[1][2] = e5;

		data[2][0] = e6;
		data[2][1] = e7;
		data[2][2] = e8;
	};
	~Matrix3() {};

	operator float* () {
		return &data[0][0];
	}

	operator const float* () const {
		return &data[0][0];
	}
	Vector3& operator [] (int index);

	const Vector3& operator [] (int index) const;
	
	Matrix3 operator * (const Matrix3& other) const;

	Vector3 operator * (const Vector3& v) const;

	Matrix3& operator = (const Matrix3& other);

	Matrix3 transposed() const;

	void translate(float x, float y);

	void setScaled(float x, float y, float z);

	void setScaled(const Vector3& v);

	void scale(float x, float y, float z);

	void scale(const Vector3& v);
	
	void setRotateX(float radians);

	void setRotateY(float radians);

	void setRotateZ(float radians);

	void rotateX(float radians);

	void rotateY(float radians);
			   
	void rotateZ(float radians);

	void setEuler(float pitch, float yaw, float roll);

};

