#include "Vector2.h"

Vector2::Vector2(const int _x, const int _y)
{
    x = _x;
    y = _y;
}

Vector2::Vector2(const Vector2& _copy)
{
    x = _copy.x;
    y = _copy.y;
}

int Vector2::X() const
{
    return x;
}

int Vector2::Y() const
{
    return y;
}

void Vector2::Set(const int _newX, const int _newY)
{
    x = _newX;
    y = _newY; 
}

void Vector2::Set(const Vector2& _other)
{
    x = _other.x;
    y = _other.y; 
}

bool Vector2::Equals(const Vector2* _other) const
{
    return x == _other->x && y == _other->y;
}
