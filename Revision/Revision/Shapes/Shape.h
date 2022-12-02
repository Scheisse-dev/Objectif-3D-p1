#pragma once
#include <windows.h>
#pragma comment(lib, "Gdiplus.lib")
#include <gdiplus.h>
#include "..\Object\Object.h"

struct Style 
{
	Gdiplus::Color backgroundColor = Gdiplus::Color::White;
};

struct Position
{
	float x;
	float y;
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
	Shape() = default; 
	Shape(Position _position);
	Shape(const Shape&) = default;
	~Shape();
#pragma endregion constructor
#pragma region methods
public: 
	Style& GetStyle(); 
	Position& GetPosition(); 
	bool IsValid() const; 
	void Init(HDC _hdc); 
	virtual void Draw(HDC _hdc); 
#pragma endregion methods
};

