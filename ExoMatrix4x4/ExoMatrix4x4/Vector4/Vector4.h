#pragma once

#include <string>

#define Epsilon 0.00001f

class Vector4
{
#pragma region f/p
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;
public:
	static const Vector4 Zero;
	static const Vector4 One;
	const float magnitude = Magnitude(*this);
#pragma endregion f/p
#pragma region constructor
public:
	Vector4(const float _x, const float _y, const float _z, const float _w);
	Vector4(const float _x, const float _y, const float _z);
	Vector4(const float _x, const float _y);
	Vector4(const float _value);
	Vector4(const Vector4& _copy);
#pragma endregion constructor
#pragma region methods
public:
	/// <summary>
	/// Return vector that is made from the absolute coponents
	/// </summary>
	/// <param name="_value">vector</param>
	/// <returns>Vector4</returns>
	static Vector4 Abs(const Vector4& _value);
	/// <summary>
	/// Returns a vector that is made from the smallest coponents of two vectors
	/// </summary>
	/// <param name="_a">vector</param>
	/// <param name="_b">vector</param>
	/// <returns>Vector4</returns>
	static Vector4 Min(const Vector4& _a, const Vector4& _b);
	/// <summary>
	/// Returns a vector that is made from the largest coponents of two vectors
	/// </summary>
	/// <param name="_a">vector</param>
	/// <param name="_b">vector</param>
	/// <returns>Vector4</returns>
	static Vector4 Max(const Vector4& _a, const Vector4& _b);

	/// <summary>
	/// Linearly interpolates between two vectors.
	/// </summary>
	/// <param name="_a">begin</param>
	/// <param name="_b">end</param>
	/// <param name="_t">time</param>
	/// <returns>Vector4</returns>
	static Vector4 Lerp(const Vector4& _a, const Vector4& _b, const float _t);
	/// <summary>
	/// Linearly interpolates between two vectors without clamping the interpolant.
	/// </summary>
	/// <param name="_a">begin</param>
	/// <param name="_b">end</param>
	/// <param name="_t">time</param>
	/// <returns>Vector4</returns>
	static Vector4 LerpUnclamped(const Vector4& _a, const Vector4& _b, const float _t);
	/// <summary>
	/// Dot Product of two vectors.
	/// </summary>
	/// <param name="_a">vector</param>
	/// <param name="_b">vector</param>
	/// <returns>Vector4</returns>
	static float Dot(const Vector4& _a, const Vector4& _b);
	/// <summary>
	/// return the length of vector
	/// </summary>
	/// <param name="_value"></param>
	/// <returns>float</returns>
	static float Magnitude(const Vector4& _value);
	/// <summary>
	/// return the distance between a and b
	/// </summary>
	/// <param name="_a"></param>
	/// <param name="_b"></param>
	/// <returns>float</returns>
	static float Distance(const Vector4& _a, const Vector4& _b);
	/// <summary>
	/// return length of vector
	/// </summary>
	/// <returns>float</returns>
	float Length() const;
	/// <summary>
	/// return squared length of vector
	/// </summary>
	/// <returns>float</returns>
	float LengthSquared() const;
	/// <summary>
	/// Set components of the vector.
	/// </summary>
	/// <param name="_x">_x</param>
	/// <param name="_y">_y</param>
	/// <param name="_z">_z</param>
	/// <param name="_w">_w</param>
	void Set(const float _x, const float _y, const float _z, const float _w);
	/// <summary>
	/// Clamp the current vector between min and max
	/// </summary>
	/// <param name="_current"></param>
	/// <param name="_min"></param>
	/// <param name="_max"></param>
	/// <returns></returns>
	static Vector4 Clamp(const Vector4 _current, const Vector4 _min, const Vector4 _max);
	/// <summary>
	/// Normalize vector between 0 and 1 
	/// </summary>
	void Normalize();

	std::string ToString() const;
#pragma endregion methods
#pragma region operator
public:
	float& operator[] (const int _index);
	bool operator>(const Vector4& _other) const;
	bool operator>=(const Vector4& _other);
	bool operator<(const Vector4& _other) const;
	bool operator<=(const Vector4& _other);
	Vector4 operator+(const Vector4& _other) const;
	Vector4& operator+=(const Vector4& _other);
	Vector4 operator-(const Vector4& _other) const;
	Vector4& operator-=(const Vector4& _other);
	Vector4 operator*(const Vector4& _other) const;
	Vector4& operator*=(const Vector4& _other);
	Vector4 operator/(const Vector4& _other) const;
	Vector4& operator/=(const Vector4& _other);
	bool operator==(const Vector4& _other) const;
	bool operator!=(const Vector4& _other) const;
	Vector4 operator-();
	Vector4 operator=(const Vector4& _other);
	operator const char* () const;
#pragma endregion operator
};

