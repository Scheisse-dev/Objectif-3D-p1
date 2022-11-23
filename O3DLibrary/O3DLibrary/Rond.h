#pragma once
#include "Object.h"
#include <Windows.h>
#include <Gdiplus.h>

namespace Core
{
	class Object;
	namespace Draw
	{
		class Rond : public Object
		{
#pragma region f/p
		private:
			HWND hWindow = HWND();
			Gdiplus::Color color = Gdiplus::Color();
			Gdiplus::Rect pos = Gdiplus::Rect();
			HDC hdc = HDC();
			PAINTSTRUCT paintStruct = PAINTSTRUCT();
#pragma endregion f/p
#pragma region constructor
		public:
			Rond() = default; 
			Rond(HWND _hWindow, Gdiplus::Color _color, Gdiplus::Rect _pos); 
#pragma endregion constructor
#pragma region methods
		public:
#pragma endregion methods
		};
	}
}