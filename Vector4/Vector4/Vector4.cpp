#include "Vector4.h"
#include <algorithm>

#pragma region constructor/destructor
Vector4::Vector4(const float _x, const float _y, const float _z, const float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}
Vector4::Vector4(const Vector4& _copy)
{
    x = _copy.x;
    y = _copy.y;
    z = _copy.z;
    w = _copy.w;
}
#pragma endregion constructor/destructor
#pragma region methods


Vector4 Vector4::Min(const Vector4& _vector)
{

    //const Vector4& _result = std::min({ _vector });
    //return _result;
   
}


#pragma region get
float Vector4::X()
{
    return x;
}

float Vector4::Y()
{
    return y;
}

float Vector4::Z()
{
    return z;
}

float Vector4::W()
{
    return w;
}
#pragma endregion get

#pragma endregion methods
#pragma region operator



float Vector4::operator/=(const Vector4& _other)
{
    return 0.0f;
}

bool Vector4::operator>=(const Vector4& _other)
{
    return false;
}

float Vector4::operator*=(const Vector4& _other)
{
    return 0.0f;
}

bool Vector4::operator<=(const Vector4& _other)
{
    return false;
}

float Vector4::operator+=(const Vector4& _other)
{
    x += _other.x;
    y += _other.y;
    return *this;
}
#pragma endregion operator

void Vector4::Set(const float _newX, const float _newY, const float _newZ, const float _newW)
{
    x = _newX;
    y = _newY;
    z = _newZ;
    w = _newW;
}
