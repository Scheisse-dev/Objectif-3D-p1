#include "Window.h"


#pragma region constructor
Window::Window(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, PWSTR _cmdLine, int _cmdShow)
{
	hInstance = _hInstance;
	hPrevInstance = _hPrevInstance;
	cmdLine = _cmdLine;
	cmdShow = _cmdShow;
}

Window::Window(const Window& _copy)
{
	hInstance = _copy.hInstance;
	hPrevInstance = _copy.hPrevInstance;
	cmdLine = _copy.cmdLine;
	cmdShow = _copy.cmdShow;
}

#pragma endregion constructor
#pragma region methods 
//int __stdcall Window::wWinApi(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, PWSTR _cmdLine, int _cmdShow)
//{
//	
//
//	WNDCLASS wc = {};
//
//	wc.hInstance = hInstance;
//	wc.lpszClassName = CLASS_NAME;
//
//	RegisterClass(&wc);
//
//
//
//	if (hwnd == NULL)
//		return 0;
//	ShowWindow(hwnd, cmdShow);
//
//	while (GetMessage(&msg, NULL, 0, 0) > 0)
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return 0;
//}


#pragma endregion methods 