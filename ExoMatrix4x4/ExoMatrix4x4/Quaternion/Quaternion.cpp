#include "Quaternion.h"
#include "../Math/Mathf.h"
#include "../AssertMacro/AssertMacro.h"
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
#pragma endregion constructor
#pragma region methods
bool Quaternion::IsEqualUsingDot(const float _dot)
{
	return _dot > 1.0f - epsilon;
}

float Quaternion::Dot(const Quaternion& _a, const Quaternion& _b)
{
	return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z + _a.w * _b.w;
}

float Quaternion::Angle(const Quaternion& _a, const Quaternion& _b)
{
	const float _dot = Mathf::Min(Mathf::Abs(Dot(_a, _b)), 1.0f);
	return IsEqualUsingDot(_dot) ? 0.0f : Mathf::Acos(_dot) * 2.0f * Mathf::Rad2Deg;
}

Quaternion Quaternion::Normalize(const Quaternion& _value)
{
	const float _num = 1.0f / Dot(_value, _value);
	return Quaternion(_value.x * _num, _value.y * _num, _value.z * _num, _value.w * _num);
}

Quaternion Quaternion::Conjugate(const Quaternion& _value)
{
	return Quaternion(-_value.x, -_value.y, -_value.z, _value.w);
}

Quaternion Quaternion::Negate(const Quaternion& _value)
{
	return Quaternion(-_value.x, -_value.y, -_value.z, -_value.w);
}

Quaternion Quaternion::Inverse(const Quaternion& _value)
{
	const float _dot = Dot(_value, _value);
	const float _invNorm = 1.0f / _dot;
	return Quaternion(-_value.x * _invNorm, -_value.y * _invNorm, -_value.z * _invNorm, -_value.w * _invNorm);
}

Quaternion Quaternion::Lerp(const Quaternion& _a, const Quaternion& _b, const float _time)
{
	const float _t = 1.0f - _time;
	Quaternion _result = Quaternion::Identity;

	const float _dot = Dot(_a, _b);
	if (_dot >= 0.0f)
	{
		_result.x = _t * _a.x + _time * _b.x;
		_result.y = _t * _a.y + _time * _b.y;
		_result.z = _t * _a.z + _time * _b.z;
		_result.w = _t * _a.w + _time * _b.w;
	}
	else
	{
		_result.x = _t * _a.x - _time * _b.x;
		_result.y = _t * _a.y - _time * _b.y;
		_result.z = _t * _a.z - _time * _b.z;
		_result.w = _t * _a.w - _time * _b.w;
	}

	const float _ls = Dot(_result, _result);
	const float _invNorm = 1.0f / Mathf::Sqrt(_ls);

	_result.x *= _invNorm;
	_result.y *= _invNorm;
	_result.z *= _invNorm;
	_result.w *= _invNorm;
	return _result;
}

Quaternion Quaternion::CreateFromYawPitchRoll(const float _yaw, const float _pitch, const float _roll)
{
	float _sr, _cr, _sp, _cp, _sy, _cy;

	const float _halfRoll = _roll * 0.5f;
	_sr = Mathf::Sin(_halfRoll);
	_cr = Mathf::Cos(_halfRoll);

	const float _halfPitch = _pitch * 0.5f;
	_sp = Mathf::Sin(_halfPitch);
	_cp = Mathf::Cos(_halfPitch);

	const float _halfYaw = _yaw * 0.5f;
	_sy = Mathf::Sin(_halfYaw);
	_cy = Mathf::Cos(_halfYaw);

	Quaternion _result = Quaternion::Identity;
	_result.x = _cy * _sp * _cr + _sy * _cp * _sr;
	_result.y = _sy * _cp * _cr - _cy * _sp * _sr;
	_result.z = _cy * _cp * _sr - _sy * _sp * _cr;
	_result.w = _cy * _cp * _cr + _sy * _sp * _sr;

	return _result;
}

float Quaternion::Length() const
{
	return Mathf::Sqrt(Dot(*this, *this));
}

float Quaternion::LengthSquared() const
{
	return Dot(*this, *this);
}
#pragma endregion methods

#pragma region operator
Quaternion Quaternion::operator+(const Quaternion& _other) const
{
	return Quaternion(x + _other.x, y + _other.y, z + _other.y, w + _other.w);
}

Quaternion Quaternion::operator-(const Quaternion& _other) const
{
	return Quaternion(x - _other.x, y - _other.y, z - _other.y, w - _other.w);
}

Quaternion Quaternion::operator*(const Quaternion& _other) const
{
	Quaternion _result = Quaternion::Identity;

	const float _x = _other.x;
	const float _y = _other.y;
	const float _z = _other.z;
	const float _w = _other.w;

	const float _cx = y * _z - _z * y;
	const float _cy = z * _x - _x * z;
	const float _cz = x * _y - _y * x;

	const float _dot = x * _x + y * _y + z * _z;

	_result.x = x * _w + _x * w + _cx;
	_result.y = y * _w + _y * w + _cy;
	_result.z = z * _w + _z * w + _cz;
	_result.w = w * _w - _dot;


	return _result;
}

Quaternion Quaternion::operator/(const Quaternion& _other) const
{
	Quaternion _result = Quaternion::Identity;

	const float _ls = Dot(_other, _other);
	const float _invNorm = 1.0f / _ls;

	const float _x = -_other.x * _invNorm;
	const float _y = -_other.y * _invNorm;
	const float _z = -_other.z * _invNorm;
	const float _w = -_other.w * _invNorm;

	const float _cx = y * _z - z * _y;
	const float _cy = z * _x - x * _z;
	const float _cz = x * _y - y * _x;

	const float _dot = x * _x + y * _y + z * _z;

	_result.x = x * _w + _x * w + _cx;
	_result.y = y * _w + _y * w + _cy;
	_result.z = z * _w + _z * w + _cz;
	_result.w = w * _w - _dot;
	return _result;
}

bool Quaternion::operator==(const Quaternion& _other) const
{
	return x == _other.x && y == _other.y && z == _other.z && w == _other.w;
}

bool Quaternion::operator!=(const Quaternion& _other) const
{
	return !this->operator==(_other);
}

float& Quaternion::operator[](const int _index)
{
	check(_index > 0 && _index < 4);
	switch (_index)
	{
	case 0: return x;
	case 1: return y;
	case 2: return z;
	case 3: return w;

	}
}


#pragma endregion operator
