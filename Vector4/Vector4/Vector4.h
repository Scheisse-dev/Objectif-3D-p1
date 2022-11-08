#pragma once

class Vector4
{
#pragma region f/p
private:
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;

#pragma endregion f/p
#pragma region constructor/destructor
public:
	Vector4() = default;
	Vector4(const float _x, const float _y, const float _z, const float _w);
	Vector4(const Vector4& _copy);
#pragma endregion constructor/destructor
#pragma region methods
public:
	Vector4 Abs(const Vector4& _other); 
	Vector4 Add(float _a);
	Vector4 Clamp(Vector4& _vector, const float _max, const float _min);
	Vector4 Min(const Vector4& _vector);
	Vector4 Max(const Vector4& _vector);
	Vector4 Lerp(const Vector4& _a, const Vector4& _b, float _t); // t = 0 / 1 
	Vector4 LerpUnclamp(const Vector4& _a, const Vector4& _b, float t); // t no clamp 
	#pragma region get
		float X();
		float Y();
		float Z();
		float W();
	#pragma endregion get
	float Clamp(float _index, const float _max, const float _min);
	float Dot(Vector4 _a, Vector4 _b);
	float Magnitude(const Vector4& _vector);
	float Distance(Vector4& _a, Vector4 _b); // size_t
	float Length(); 
	float LengthSquared(); 
	void Set(const float _newX, const float _newY, const float _newZ, const float _newW);
	void Normalize(); 

#pragma endregion methods 
#pragma region operator
public: 
	bool operator==(const Vector4& _other);
	bool operator>=(const Vector4& _other);
	bool operator<=(const Vector4& _other);
	bool operator<(const Vector4& _other);
	bool operator>(const Vector4& _other);
	Vector4 operator/=(const Vector4& _other);
	Vector4 operator*=(const Vector4& _other);
	Vector4 operator+=(const Vector4& _other);
	float operator+(const Vector4& _other);
	float operator*(const Vector4& _other);
	float operator/(const Vector4& _other);
	float operator-(const Vector4& _other);
	//TODO add []

#pragma endregion operator
};

