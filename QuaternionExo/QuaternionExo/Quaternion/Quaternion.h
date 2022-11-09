#pragma once
#include "../Mathf/Mathf.h"
#include <string>

#define Epsilon 0.00001f

class Quaternion
{
#pragma region f/p
private:
	float x = 0.0f; 
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;
#pragma endregion f/p
#pragma region constructor
public: 
	Quaternion(const float _x, const float _y, const float _z, const float _w);

	Quaternion(const float _value);
	Quaternion(const Quaternion& _copy);

#pragma endregion constructor
#pragma region methods
public:
	/// <summary>
	/// Normalize vector between 0 and 1 
	/// </summary>
	static Quaternion Normalize(Quaternion& _value);
	/// <summary>
	/// Negate the Quaternion 
	/// </summary>
	/// <param name="_value">Quaternion</param>
	/// <returns>Quaternion</returns>
	static Quaternion Negate(const Quaternion& _value);
	/// <summary>
	/// inverse the Quaternion
	/// </summary>
	/// <param name="_value">Quaternion</param>
	/// <returns>Quaternion</returns>
	static Quaternion Inverse(const Quaternion& _value); 
	/// <summary>
	/// Linearly interpolates between two vectors.
	/// </summary>
	/// <param name="_a">begin</param>
	/// <param name="_b">end</param>
	/// <param name="_t">time</param>
	/// <returns>Vector4</returns>
	static Quaternion Lerp(const Quaternion& _a, const Quaternion& _b, const float _t);
	// Identify
	static float Dot(const Quaternion& _a, const Quaternion& _b);
	/// <summary>
	/// Retrun the Angle Degree
	/// </summary>
	/// <param name="_a">Quaternion</param>
	/// <param name="_b">Quaternion</param>
	/// <returns>float</returns>
	static float Angle(const Quaternion& _a, const Quaternion& _b);
	/// <summary>
	/// return length of the Quaternion
	/// </summary>
	/// <returns></returns>
	float Length() const;
	/// <summary>
	/// Return the Squared length of th Quaternion
	/// </summary>
	/// <returns>float</returns>
	float LengthSquared() const ;
	/// <summary>
	/// conjugate the Quaternion
	/// </summary>
	/// <param name="_value">Quaternion</param>
	/// <returns>Quaternion</returns>
	static Quaternion Conjugate(const Quaternion& _value);
	/// <summary>
	/// transform the Quaternion to type string with format
	/// </summary>
	/// <returns>String</returns>
	std::string ToString() const;
#pragma endregion methods
#pragma region operator
public:
	// -
	// -
	// +
	Quaternion operator*(const Quaternion& _other) const;
	Quaternion& operator*=(const Quaternion& _other);
	Quaternion operator/(const Quaternion& _other) const; 
	// ==
	// =
	bool operator!=(const Quaternion& _other); 
	// []
	//
#pragma endregion operator
};

