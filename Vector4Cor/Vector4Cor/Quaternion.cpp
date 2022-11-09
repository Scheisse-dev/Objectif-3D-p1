#include "Quaternion.h"
#include "Mathf.h"
#pragma region f/p 
Quaternion const Quaternion::Identity = Quaternion(0, 0, 0, 1);
#pragma endregion f/p
#pragma region constructor
Quaternion::Quaternion(const float _x, const float _y, const float _z, const float _w)
{
	x = _x;
	y = _y;
	z = _z; 
	w = _w;
}

Quaternion::Quaternion(const Quaternion& _copy)
{
	x = _copy.x;
	y = _copy.y;
	z = _copy.z;
	w = _copy.w;
}

bool Quaternion::IsEqualUsingDot(const float _dot)
{
	return _dot > 1.0f - epsilon; 
}

float Quaternion::Dot(const Quaternion& _a, const Quaternion& _b)
{
	return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z + _a.w * _b.w;
}

Quaternion Quaternion::Normalize(const Quaternion& _value)
{
	const float _num = 1.0f / Dot(_value, _value);
	return Quaternion(_value.x * _num, _value.y * _num, _value.z * _num, _value.w * _num);
}

Quaternion Quaternion::Conjugate(const Quaternion& _value)
{
	return Quaternion(-_value.x, -_value.y, -_value.z, -_value.w );
}

float Quaternion::Angle(const Quaternion& _a, const Quaternion& _b)
{
	const float _dot = Mathf::Min(Mathf::Abs(Dot(_a, _b)), 1.0f);
	return IsEqualUsingDot(_dot) ? 0.0f : Mathf::Acos(_dot) * 2.0f * Mathf::Rad2Deg;

#pragma endregion constructor


#pragma region methods

#pragma endregion methods

#pragma region operator


#pragma endregion operator