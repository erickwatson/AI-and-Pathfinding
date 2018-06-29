#pragma once

class Vector4 {
public:
	union {
		struct {
			float x, y, z, w;
		};

		float data[4];
	};

	Vector4();
	Vector4(float, float, float, float);

	float operator [] (int index) const;
	operator float* () {
		return &data[0];
	}
	operator const float* () const {
		return &data[0];
	}

	Vector4 operator + (const Vector4& other) const;

	Vector4 operator - (const Vector4& other) const;

	Vector4& operator += (const Vector4& other);

	Vector4& operator -= (const Vector4& other);

	Vector4& operator = (const Vector4& other);

	Vector4 operator * (float scalar) const;

	Vector4& operator *= (float scalar);

	Vector4& operator /= (float scalar);

	float dot(const Vector4& other);

	Vector4 cross(const Vector4& other);

	float magnitude() const;	float magnitudeSqr() const;
	float distance(const Vector4& other) const;

	void normalise();

	Vector4 normalised();
};

Vector4 operator *(float scalar, Vector4 vector);