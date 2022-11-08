#pragma once
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
	Quaternion(const Quaternion& _copy);

#pragma endregion constructor
#pragma region methods
public:
	void Normalize();
	static Quaternion Negate(const Quaternion& _value);
	static Quaternion Inverse(const Quaternion& _value); 
	// Lerp
	// Dot
	// Identify
	static float Angle(const Quaternion& _a, const Quaternion& _b);
	static float Length(const Quaternion& _value);
	static float LengthSquared(const Quaternion& _value);
	// Conjugate
#pragma endregion methods
#pragma region operator
public:
	// -
	// -
	// +
	// *
	// * float ? 
	// /
	// ==
	// =
	// ?=
	// []
	//
#pragma endregion operator
};

