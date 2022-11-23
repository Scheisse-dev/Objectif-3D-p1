#include "Shape.h"


#pragma region constructor
Core::Shape::Shape(Position _position)
{
	position = _position; 
}

Core::Shape::~Shape()
{
	delete pen;
	pen = nullptr;
	delete graphics;
	graphics = nullptr; 
}


#pragma endregion constructor

#pragma region methods

Core::Style& Core::Shape::GetStyle()
{
	return style;
}
Core::Position& Core::Shape::GetPosition()
{
	return position; 
}
bool Core::Shape::IsValid() const
{
	return pen != nullptr && graphics != nullptr; 
}
void Core::Shape::Init(HDC _hdc)
{
	graphics = new Gdiplus::Graphics(_hdc); 
	pen = new Gdiplus::Pen(style.backgroundColor); 
}
void Core::Shape::Draw(HDC _hdc)
{
	if (!IsValid()) Init(_hdc); 
}
#pragma endregion methods