#pragma once
#include "windows.h"

#ifndef UNICODE
#define UNICODE
#endif

class Window
{
#pragma region f/p
private:
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	PWSTR cmdLine; 
	int cmdShow; 
	MSG msg = {};

#pragma endregion f/p
#pragma region constructor
public:
	Window(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, PWSTR _cmdLine, int _cmdShow);
	Window(const Window& _copy);
#pragma endregion constructor
#pragma region methods 
public:
	int WINAPI wWinApi(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, PWSTR _cmdLine, int _cmdShow);

#pragma endregion methods
};

