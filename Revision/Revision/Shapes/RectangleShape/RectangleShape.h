#pragma once
#include "..\Shape.h"


class RectangleShape : public Shape
{
#pragma region f/p
private: 
	int width = 20; 
	int height = 10; 
#pragma endregion f/p
#pragma region constructor
public: 
	RectangleShape(Position _position, int _width, int _height); 
#pragma endregion constructor
#pragma region override
public : 
	void Draw(HDC _hdc) override; 
};

