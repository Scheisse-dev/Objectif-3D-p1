#pragma once
#include <windows.h>


class Rect
{
#pragma region f/p
private:
	int width = 0; 
	int height = 0;
	int x = 0; 
	int y = 0;
	int xMax = 0;
	int yMax = 0; 
#pragma endregion f/p
#pragma region constructor
public:
	Rect() = default; 
	Rect(const int _width, const int _height, const int _x, const int _y);
	Rect(const Rect& _copy); 
#pragma endregion constructor
#pragma region methods
public:
	bool Contains(const int _x, const int _y);
	int X() const;
	int Y() const;

#pragma endregion methods
};

