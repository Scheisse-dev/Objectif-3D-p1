#pragma once
#include <windows.h>
#include <gdiplus.h>
#include "Object.h"



namespace Core
{
	struct Position
	{
		float x;
		float y;
	};

	struct Style
	{
		Gdiplus::Color backgroundColor= Gdiplus::Color::White;
	};

	class Shape
	{
#pragma region f/p
	protected:
		Gdiplus::Pen* pen = nullptr; 
		Gdiplus::Graphics* graphics = nullptr; 
		Style style = Style(); 
		Position position = Position(); 
#pragma endregion f/p
#pragma region constructor
	public: 
		O3DLIBRARY_API Shape() = default;
		O3DLIBRARY_API Shape(Position _position);
		O3DLIBRARY_API Shape(const Shape&) = default; 
		O3DLIBRARY_API ~Shape();
#pragma region constructor
#pragma region methods
	public: 
		O3DLIBRARY_API Style& GetStyle();
		O3DLIBRARY_API Position& GetPosition();
		O3DLIBRARY_API bool IsValid() const;
		O3DLIBRARY_API void Init(HDC _hdc);
		O3DLIBRARY_API virtual void Draw(HDC _hdc) ;

#pragma endregion methods
	};

}