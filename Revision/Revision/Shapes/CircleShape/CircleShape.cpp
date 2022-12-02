#include "CircleShape.h"


#pragma region constructor 
CircleShape::CircleShape(const Position& _position, const float _radius)
	:Shape(_position)
{
	radius = _radius; 
}
#pragma endregion constructor 
#pragma region methods
void CircleShape::Draw(HDC _hdc)
{
	Shape::Draw(_hdc); 
	if (!IsValid()) return; 
	Gdiplus::Rect _rect = Gdiplus::Rect(position.x, position.y, radius, radius); 
	graphics->FillEllipse(new Gdiplus::SolidBrush(style.backgroundColor), _rect); 
}
#pragma endregion methods