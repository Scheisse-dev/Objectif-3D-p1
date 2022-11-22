#include "Window.h"
#include "WindowMenu.h"


#pragma region constructor
Core::Window::Window(const PrimitiveType::FString& _name, const int _width, const int _height)
{
	name = _name; 
	width = _width;
	height = _height; 

	const LPCWSTR _className = L"Default Window"; 
	HINSTANCE _instance = HINSTANCE(); 
	WNDCLASS _wndClass = {};
	_wndClass.lpszClassName = _className; 
	_wndClass.hInstance = _instance; 
	_wndClass.lpfnWndProc = WindowProc_Internal; 
	_wndClass.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
	_wndClass.hCursor = LoadCursor(_instance, IDC_HAND); 
	RegisterClass(&_wndClass); 


	windowInstance = CreateWindowEx(0, _className, _name.ToWString().c_str(), 
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZE , CW_USEDEFAULT, CW_USEDEFAULT,
		width, height, nullptr, nullptr, _instance, this);

	HWND textField = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"TEST", WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 20, 140, 20, windowInstance, nullptr, _instance, nullptr); 
}

Core::Window::~Window()
{
	for (std::pair<const char*, WindowMenu*> _p : menus)
		delete _p.second;
	menus.clear(); 
}
#pragma endregion constructor
#pragma region methods
LRESULT _stdcall Core::Window::WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (_hWindow == nullptr) return 0;
	switch (_msg)
	{
	case WM_CREATE:
		AddMenus(_hWindow); 
		break;
	case WM_DESTROY:
	{
		Close();
		break; 
	}
	default:
		return DefWindowProcW(_hWindow, _msg, _wp, _lp);
	}
}
LRESULT _stdcall Core::Window::WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (_msg == WM_NCCREATE)
	{
		SetWindowLongPtr(_hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
		return true; 
	}
	return reinterpret_cast<Window*>(GetWindowLongPtr(_hWindow, GWLP_USERDATA))->WindowProc(_hWindow, _msg, _wp, _lp);
}
O3DLIBRARY_API void Core::Window::Update()
{
	MSG _msg = {};
	while (isOpen)
	{
		while (PeekMessage(&_msg, windowInstance, 0, 0, PM_REMOVE))
		{
			if (!TranslateAccelerator(_msg.hwnd, nullptr, &_msg))
			{
				TranslateMessage(&_msg);
				DispatchMessage(&_msg); 
			}
		}
	}
}
O3DLIBRARY_API void Core::Window::AddMenus(HWND _hwnd)
{
	const WindowMenu* _menu = CreateWindowMenu(""); 
	WindowMenu* _fileMenu = CreateWindowMenu("File"); 
	WindowMenu* _newMenu = CreateWindowMenu("New");
	WindowMenu* _editMenu = CreateWindowMenu("Edit");
	_editMenu->CreateButtonMenu("Copy"); 
	_newMenu->CreateButtonMenu("Project");
	_fileMenu->CreatePopUpMenu(_newMenu); 
	_fileMenu->CreateButtonMenu("Close"); 
	_menu->CreatePopUpMenu(_fileMenu);
	_menu->CreatePopUpMenu(_fileMenu);
	SetMenu(_hwnd, *_menu); 

}

O3DLIBRARY_API Core::WindowMenu* Core::Window::CreateWindowMenu(const char* _name)
{
	WindowMenu* _menu = new WindowMenu(this, _name); 
	menus.insert(std::pair<const char*, WindowMenu*>(_name, _menu));
	return _menu; 
}

O3DLIBRARY_API int Core::Window::MenusCount() const
{
	return menus.size();
}

O3DLIBRARY_API void Core::Window::RegisterMenu(WindowMenu* _menu)
{
	menus.insert(std::pair<const char*, WindowMenu*>(_menu->Name(), _menu)); 
}

void Core::Window::Open()
{
	if (windowInstance == nullptr) return;
	isOpen = true; 
	ShowWindow(windowInstance, SW_SHOWDEFAULT);
	UpdateWindow(windowInstance); 
	Update();
}
void Core::Window::Close()
{
	CloseWindow(windowInstance);
	isOpen = false; 
}
#pragma endregion methods

