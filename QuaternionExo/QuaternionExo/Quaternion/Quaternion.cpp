#include "Quaternion.h"
#include <format>


#pragma region constructor 
Quaternion::Quaternion(const float _x, const float _y, const float _z, const float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;

}

Quaternion::Quaternion(const float _value)
{
	x = y = z = w = _value;
}

Quaternion::Quaternion(const Quaternion& _copy)
{
	x = _copy.x;
	y = _copy.y;
	z = _copy.z;
	w = _copy.w;
}

#pragma endregion constructor 

#pragma region methods

Quaternion Quaternion::Normalize(Quaternion& _value)
{
	float _length = Mathf::Sqrt(Dot(_value, _value));
	if (_length > Epsilon)
		_value = _value / _length;
	else _value = Quaternion(0);
	return _value;
}
Quaternion Quaternion::Negate(const Quaternion& _value)
{
	return Quaternion(-_value.x, -_value.y, -_value.z,-_value.w);
}
Quaternion Quaternion::Inverse(const Quaternion& _value)
{
	float _tmp = Dot(_value, _value);
	float _inv = 1.0f / _tmp;
	return Quaternion(-(_value.x) * _inv, -(_value.y) * _inv, -(_value.z) * _inv, -(_value.w) * _inv);
}
Quaternion Quaternion::Lerp(const Quaternion& _a, const Quaternion& _b, const float _t)
{
	return _a;
}
/// <summary>
/// return the dot between two Quaternion
/// </summary>
/// <param name="_a">Quaternion</param>
/// <param name="_b">Quaternion</param>
/// <returns>Quaternion</returns>
float Quaternion::Dot(const Quaternion& _a, const Quaternion& _b)
{
	return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z + _a.w * _b.w;
}

float Quaternion::Angle(const Quaternion& _a, const Quaternion& _b)
{
	return 0.0f;
}

/// <summary>
/// return the length of the Qyaternion
/// </summary>
/// <returns>float</returns>
float Quaternion::Length() const
{
	return Mathf::Sqrt(Dot(*this, *this));
}

/// <summary>
/// return the Squared length of the Quaternion
/// </summary>
/// <returns>float</returns>
float Quaternion::LengthSquared() const
{
	return Dot(*this, *this);
}

Quaternion Quaternion::Conjugate(const Quaternion& _value)
{
	return Quaternion(_value.x - _value.x * 2, _value.y - _value.y * 2, _value.z - _value.z * 2, _value.w);;
	
}

std::string Quaternion::ToString() const
{
	return std::format("X: {} Y: {} Z: {} W: {}", x, y, z, w);
}

#pragma endregion methods

#pragma region operator


Quaternion Quaternion::operator*(const Quaternion& _other) const
{
	return Quaternion(x * _other.x, y * _other.y, z * _other.z, w * _other.w);
}

Quaternion& Quaternion::operator*=(const Quaternion& _other)
{
	x *= _other.x;
	y *= _other.y;
	z *= _other.z;
	w *= _other.w;
	return *this;
}

Quaternion Quaternion::operator/(const Quaternion& _other) const
{
	return Quaternion(x / _other.x, y / _other.y, z / _other.z, w / _other.w);
}

bool Quaternion::operator!=(const Quaternion& _other)
{
	return x != _other.x && y != _other.y && z != _other.z && w != _other.w;
}





#pragma endregion operator

