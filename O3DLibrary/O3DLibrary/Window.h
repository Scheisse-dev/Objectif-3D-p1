#pragma once
#include <Windows.h>
#include <map>
#include <gdiplus.h>
#include <vector>
#include "FString.h"
#include "Shape.h"
#include "Object.h"

#pragma comment(lib, "Gdiplus.lib")

namespace Core
{
	class WindowMenu;

	class Window : public Object
	{
#pragma region f/p
	public:
		Gdiplus::Color color = Gdiplus::Color(255, 255, 0, 0);
		Gdiplus::Rect pos = Gdiplus::Rect(10, 10, 100, 100);
	private:
		std::vector<class Shape*> shapes = std::vector<Shape*>(); 
		HWND windowInstance = nullptr; 
		PrimitiveType::FString name = "";
		int width = 1920;
		int height = 1080;
		bool isOpen = true; 
		std::map<const char*, WindowMenu*> menus = std::map<const char*, WindowMenu*>();

		HDC hdc = HDC();
		PAINTSTRUCT paintStruct = PAINTSTRUCT(); 
		Gdiplus::GdiplusStartupInput gdiplusStartupInput = Gdiplus::GdiplusStartupInput();
		ULONG_PTR gdiplusToken = 0;
#pragma endregion f/p
#pragma region constructor
	public: 
		O3DLIBRARY_API Window() = default;
		O3DLIBRARY_API Window(const PrimitiveType::FString& _name, const int _width, const int _height);
		O3DLIBRARY_API ~Window() override; 
#pragma endregion constructor
#pragma region methods
	private: 
		O3DLIBRARY_API LRESULT _stdcall WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		O3DLIBRARY_API static LRESULT _stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
	protected: 
		O3DLIBRARY_API virtual void Update();
		O3DLIBRARY_API virtual void AddMenus(HWND _hwnd);
		O3DLIBRARY_API WindowMenu* CreateWindowMenu(const char* _name);
	public: 
		O3DLIBRARY_API void Register(Shape* _shape); 
		O3DLIBRARY_API int MenusCount() const;
		O3DLIBRARY_API void RegisterMenu(WindowMenu* _menu);
		O3DLIBRARY_API void Open();
		O3DLIBRARY_API void Close();
#pragma endregion methods
	};
}
