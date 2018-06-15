#pragma once
#include "Vector3.h"
#include "Vector2.h"

struct Matrix3
{
	Matrix3();
	Matrix3(float m00, float m01, float m02,		//Initialising 3x3 matrix with paramater contents
			float m10, float m11, float m12,
			float m20, float m21, float m22);
	~Matrix3();

	Vector3 operator*(Vector3 rhs);
	Matrix3 operator*(Matrix3 rhs);

	Vector3& operator[](int index);
	explicit operator float*();

	void setRotateX(float fRadians);
	void setRotateY(float fRadians);
	void setRotateZ(float fRadians);

	void setPosition(float x, float y);
	void setPosition(Vector2 pos);

	void setScale(float x, float y);
	void setScale(Vector2 scale);

	Vector2 getPosition();
	

	float m[3][3];
};

