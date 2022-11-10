#include "Vector4.h"
#include <exception>
#include <format>
#include <string>
#include "../Math/Mathf.h"
#include "../AssertMacro/AssertMacro.h"

#pragma region f/p
Vector4 const Vector4::Zero = Vector4(0);
Vector4 const Vector4::One = Vector4(1);

#pragma endregion f/p

#pragma region constructor
Vector4::Vector4(const float _x, const float _y, const float _z, const float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Vector4::Vector4(const float _x, const float _y, const float _z)
	:Vector4(_x, _y, _z, 0)
{ }

Vector4::Vector4(const float _x, const float _y)
	:Vector4(_x, _y, 0, 0)
{ }

Vector4::Vector4(const float _value)
{
	x = y = z = w = _value;
}

Vector4::Vector4(const Vector4& _copy)
{
	x = _copy.x;
	y = _copy.y;
	z = _copy.z;
	w = _copy.w;
}



#pragma endregion constructor

#pragma region methods
Vector4 Vector4::Abs(const Vector4& _value)
{
	return Vector4(Mathf::Abs(_value.x), Mathf::Abs(_value.y), Mathf::Abs(_value.z), Mathf::Abs(_value.w));
}
Vector4 Vector4::Min(const Vector4& _a, const Vector4& _b)
{
	return Vector4(Mathf::Min(_a.x, _b.x), Mathf::Min(_a.y, _b.y), Mathf::Min(_a.z, _b.z), Mathf::Min(_a.w, _b.w));
}
Vector4 Vector4::Max(const Vector4& _a, const Vector4& _b)
{
	return Vector4(Mathf::Max(_a.x, _b.x), Mathf::Max(_a.y, _b.y), Mathf::Max(_a.z, _b.z), Mathf::Max(_a.w, _b.w));
}



Vector4 Vector4::Lerp(const Vector4& _a, const Vector4& _b, const float _t)
{
	const float _time = Mathf::Clamp01(_t);
	return Vector4(_a.x + (_b.x - _a.x) * _time,
		_a.y + (_b.y - _a.y) * _time,
		_a.z + (_b.z - _a.z) * _time,
		_a.w + (_b.w - _a.w) * _time);
}
Vector4 Vector4::LerpUnclamped(const Vector4& _a, const Vector4& _b, const float _t)
{
	return Vector4(_a.x + (_b.x - _a.x) * _t,
		_a.y + (_b.y - _a.y) * _t,
		_a.z + (_b.z - _a.z) * _t,
		_a.w + (_b.w - _a.w) * _t);
}
float Vector4::Dot(const Vector4& _a, const Vector4& _b)
{
	return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z + _a.w * _b.w;
}
float Vector4::Magnitude(const Vector4& _value)
{
	return Mathf::Sqrt(Dot(_value, _value));
}
float Vector4::Distance(const Vector4& _a, const Vector4& _b)
{
	return Magnitude(_a - _b);
}
float Vector4::Length() const
{
	return Mathf::Sqrt(Dot(*this, *this));
}
float Vector4::LengthSquared() const
{
	return Dot(*this, *this);
}
void Vector4::Set(const float _x, const float _y, const float _z, const float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

#pragma endregion methods
#pragma region operator
Vector4 Vector4::Clamp(const Vector4 _current, const Vector4 _min, const Vector4 _max)
{
	return Mathf::Clamp(_current, _min, _max);
}
void Vector4::Normalize()
{
	if (magnitude > Epsilon)
		*this = *this / magnitude;
	else *this = Zero;
}
std::string Vector4::ToString() const
{
	return std::format("{},{},{},{}", x, y, z, w);
}
float& Vector4::operator[](const int _index)
{
	check(_index > 0 && _index < 4)
		switch (_index)
		{
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
		default:
			throw std::exception("index out of range");
		}
}
bool Vector4::operator>(const Vector4& _other) const
{
	return x > _other.x && y > _other.y && z > _other.z && w > _other.w;
}
bool Vector4::operator>=(const Vector4& _other)
{
	return x >= _other.x && y >= _other.y && z >= _other.z && w >= _other.w;
}
bool Vector4::operator<(const Vector4& _other) const
{
	return x < _other.x&& y < _other.y&& z < _other.z&& w < _other.w;
}
bool Vector4::operator<=(const Vector4& _other)
{
	return x <= _other.x && y <= _other.y && z <= _other.z && w <= _other.w;
}
Vector4 Vector4::operator+(const Vector4& _other) const
{
	return Vector4(x + _other.x, y + _other.y, z + _other.z, w + _other.w);
}
Vector4& Vector4::operator+=(const Vector4& _other)
{
	x += _other.x;
	y += _other.y;
	z += _other.z;
	w += _other.w;
	return *this;

}
Vector4 Vector4::operator-(const Vector4& _other) const
{
	return Vector4(x - _other.x, y - _other.y, z - _other.z, w - _other.w);
}
Vector4& Vector4::operator-=(const Vector4& _other)
{
	x -= _other.x;
	y -= _other.y;
	z -= _other.z;
	w -= _other.w;
	return *this;
}
Vector4 Vector4::operator*(const Vector4& _other) const
{
	return Vector4(x * _other.x, y * _other.y, z * _other.z, w * _other.w);
}
Vector4& Vector4::operator*=(const Vector4& _other)
{
	x *= _other.x;
	y *= _other.y;
	z *= _other.z;
	w *= _other.w;
	return *this;
}
Vector4 Vector4::operator/(const Vector4& _other) const
{
	return Vector4(x / _other.x, y / _other.y, z / _other.z, w / _other.w);
}
Vector4& Vector4::operator/=(const Vector4& _other)
{
	x /= _other.x;
	y /= _other.y;
	z /= _other.z;
	w /= _other.w;
	return *this;
}
bool Vector4::operator==(const Vector4& _other) const
{
	return x == _other.x && y == _other.y && z == _other.z && w == _other.w;
}
bool Vector4::operator!=(const Vector4& _other) const
{
	return x != _other.x && y != _other.y && z != _other.z && w != _other.w;
}
Vector4 Vector4::operator-()
{
	x = -x;
	y = -y;
	z = -z;
	w = -w;
	return *this;
}
Vector4 Vector4::operator=(const Vector4& _other)
{
	x = _other.x;
	y = _other.y;
	z = _other.z;
	w = _other.w;
	return *this;
}
Vector4::operator const char* () const
{
	const std::string  _str = std::format("({}, {}, {}, {})", x, y, z, w);
	return _str.c_str();
}
#pragma endregion operator
