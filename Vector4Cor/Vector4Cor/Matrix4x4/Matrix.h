#pragma once

class Quaternion; 

class Matrix4x4
{
#pragma region f/p
private:
	float m11;
	float m12;
	float m13;
	float m14;

	float m21;
	float m22;
	float m23;
	float m24;

	float m31;
	float m32;
	float m33;
	float m34;

	float m41;
	float m42;
	float m43;
	float m44;
public:
	static const Matrix4x4 Identity;

#pragma endregion f/p
#pragma region constructor
public: 
	Matrix4x4() = default;
	Matrix4x4(const float _m11, const float _m12, const float _m13, const float _m14,
		const float _m21, const float _m22, const float _m23, const float _m24,
		const float _m31, const float _m32, const float _m33, const float _m34,
		const float _m41, const float _m42, const float _m43, const float _m44);
	Matrix4x4(const Matrix4x4& _copy);
#pragma endregion constructor
#pragma region Methods
public:
	static Matrix4x4 CreateTranslation(const float _x, const float _y, const float _z);
	static Matrix4x4 CreateScale(const float _x, const float _y, const float _z);
	static Matrix4x4 CreateRotateX(const float _radians);
	static Matrix4x4 CreateRotateY(const float _radians);
	static Matrix4x4 CreateRotateZ(const float _radians);
	static Matrix4x4 CreateOrthographic(const float _width, const float _height, const float _nearPlane, const float _farPlane);
	static Matrix4x4 CreateFromQuaternion(const Quaternion& _quaternion);
	static Matrix4x4 CreateFromYawPitchRoll(const float _yaw, const float _pitch, const float _roll); 
	static Matrix4x4 Lerp(const Matrix4x4& _a, const Matrix4x4& _b, const float _t);
	float Determinant() const; 
	bool IsIdentity(const Matrix4x4& _other);
#pragma endregion Methods

#pragma region operator
public:
	Matrix4x4 operator-() const;
	Matrix4x4 operator+(const Matrix4x4& _other);
	Matrix4x4 operator-(const Matrix4x4& _other);
	Matrix4x4 operator*(const Matrix4x4& _other);
	bool operator==(const Matrix4x4& _other);
	bool operator!=(const Matrix4x4& _other);
#pragma endregion operator
};

