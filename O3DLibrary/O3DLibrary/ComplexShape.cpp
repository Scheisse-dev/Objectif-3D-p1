#include "ComplexShape.h"

#pragma region constructor
Core::ComplexShape::ComplexShape(const std::vector<Gdiplus::PointF>& _points)
	:Shape({ 0, 0 })
{
	points = _points;
}
#pragma endregion constructor
#pragma region methods
void Core::ComplexShape::Draw(HDC _hdc)
{
	Shape::Draw(_hdc); 
	if (!IsValid()) return;
	graphics->FillPolygon(new Gdiplus::SolidBrush(style.backgroundColor), points.data(), points.size());
}
#pragma endregion methods



