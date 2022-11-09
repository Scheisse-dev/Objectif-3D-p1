#pragma once
class Quaternion
{
#pragma region f/p
public:
	static inline const float epsilon = 0.000001f; 
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;
	static const Quaternion Identity ;
#pragma endregion f/p
#pragma region constructor
public: 
	Quaternion(const float _x, const float _y, const float _z, const float _w);
	Quaternion(const Quaternion& _copy);
#pragma endregion constructor
#pragma region methods
private: 
	static bool IsEqualUsingDot(const float _dot); 
public: 
	static float Dot(const Quaternion& _a, const Quaternion& _b);
	static float Angle(const Quaternion& _a, const Quaternion& _b);
	static Quaternion Normalize(const Quaternion& _value);
	static Quaternion Conjugate(const Quaternion& _value);
#pragma endregion methods
#pragma region operator
public:

#pragma endregion operator
};

