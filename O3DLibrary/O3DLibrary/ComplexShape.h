#pragma once
#include "Shape.h"
#include <vector>
namespace Core
{
	class O3DLIBRARY_API ComplexShape : public Shape
	{
#pragma region f/p
	private: 
		std::vector<Gdiplus::PointF> points = std::vector<Gdiplus::PointF>(); 
#pragma endregion f/p
#pragma region constructor
	public:
		ComplexShape(const std::vector<Gdiplus::PointF>& _points);
#pragma endregion constructor
#pragma region methods
	public:
		void Draw(HDC _hdc) override; 
#pragma endregion methods
	};

}