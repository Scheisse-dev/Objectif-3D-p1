#pragma once
#include "..\Object/Object.h"
#include <Windows.h>
#include <vector>;
#include <string>;
#include <gdiplus.h>
#include <map>
#include "..\Shapes\Shape.h"
#include "..\Shapes\RectangleShape\RectangleShape.h"

class WindowItem;

class Window : public Object
{
#pragma region f/p
private:
	HWND windowInstance = nullptr; 
	bool isOpen = true; 
	std::string name = ""; 
	std::map<std::string, WindowItem*> menus = std::map<std::string, WindowItem*>();
	int width = 1920; 
	int height = 1080;


	std::vector<class Shape*> shapes = std::vector<Shape*>();
	HDC hdc = HDC(); 
	PAINTSTRUCT paintStruct = PAINTSTRUCT();
	Gdiplus::GdiplusStartupInput gdiplusStartupInput = Gdiplus::GdiplusStartupInput();
	ULONG_PTR gdiplusToken = 0;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Window() = default;
	Window(const std::string& _name, const int _width, const int _height);
	~Window() override; 
#pragma endregion constructor/destructor
#pragma region methods
private: 
	LRESULT _stdcall WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
	static LRESULT _stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
protected:
	virtual void Update(); 
	virtual void AddMenus(HWND _hwnd);
	WindowItem* CreateWindowMenu(std::string _name);
public:
	void Register(Shape* _shape);
	int MenusCount() const; 
	void RegisterMenu(WindowItem* _menu);
	void Open(); 
	void Close(); 

#pragma endregion methods

};

