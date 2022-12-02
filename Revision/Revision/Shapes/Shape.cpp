#include "Shape.h"

#pragma region constructor
Shape::Shape(Position _position)
{
    position = _position;
}

Shape::~Shape()
{
    delete pen;
    pen = nullptr;
    delete graphics;
    graphics = nullptr;
}
#pragma endregion constructor
#pragma region methods
Style& Shape::GetStyle()
{
    return style; 
}

Position& Shape::GetPosition()
{
    return position; 
}

bool Shape::IsValid() const
{
    return pen != nullptr && graphics != nullptr;
}

void Shape::Init(HDC _hdc)
{
    graphics = new Gdiplus::Graphics(_hdc);
    pen = new Gdiplus::Pen(style.backgroundColor);
}

void Shape::Draw(HDC _hdc)
{
    if (!IsValid()) Init(_hdc);
}
#pragma endregion methods