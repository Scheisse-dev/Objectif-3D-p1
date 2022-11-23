#include "Rond.h"


#pragma region constructor
Core::Draw::Rond::Rond(HWND _hWindow, Gdiplus::Color _color, Gdiplus::Rect _pos)
{
	hWindow = _hWindow;
	color = _color;
	pos = _pos; 

	hdc = BeginPaint(_hWindow, &paintStruct);
	Gdiplus::Graphics _graphics(hdc);
	Gdiplus::Pen _pen(Gdiplus::Color::White);
	Gdiplus::Size _size = Gdiplus::Size();
	Gdiplus::Point _point = Gdiplus::Point(_size);

	_graphics.DrawEllipse(&_pen, _pos);
	_graphics.FillEllipse(new Gdiplus::SolidBrush(_color), _pos);
	EndPaint(_hWindow, &paintStruct);
	
}
#pragma endregion constructor
#pragma region methods
#pragma endregion methods


