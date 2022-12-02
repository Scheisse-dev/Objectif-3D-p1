#pragma once
#include "..\Shape.h"
#include <vector>

class ComplexShape : public Shape
{
#pragma region f/p
private: 
	std::vector<Gdiplus::PointF> points = std::vector<Gdiplus::PointF>(); 
#pragma endregion f/p
#pragma region constructor
	ComplexShape(const std::vector<Gdiplus::PointF>& _points);
#pragma endregion constructor
#pragma region override
	void Draw(HDC _hdc) override;
#pragma endregion override
};

