#include "Window.h"
#include "WindowItem/WindowItem.h"


#pragma region f/p

#pragma endregion f/p
#pragma region constructor/destructor
Window::Window(const std::string& _name, const int _width, const int _height)
{
	name = _name; 
	width = _width; 
	height = _height;

	const LPCWSTR _className = L"Default Window"; 
	HINSTANCE _instance = HINSTANCE(); 
	WNDCLASS _wndClass = {};
	_wndClass.lpszClassName = _className; 
	_wndClass.hInstance = _instance; 
	_wndClass.style = CS_HREDRAW | CS_VREDRAW;
	_wndClass.lpfnWndProc = WindowProc_Internal; 
	_wndClass.hbrBackground = CreateSolidBrush(RGB(150, 150, 150)); 
	_wndClass.hCursor = LoadCursor(_instance, IDC_HAND); 
	RegisterClass(&_wndClass); 

	std::wstring _wName = std::wstring(_name.begin(), _name.end()); 
	windowInstance = CreateWindowEx(0, _className, _wName.c_str(),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZE, CW_USEDEFAULT, CW_USEDEFAULT, 
		width, height, nullptr, nullptr, _instance, this); 

	HWND textField = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"TEST", WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 20, 140, 20, windowInstance, nullptr, _instance, nullptr);
	SetWindowTextA(windowInstance, _name.c_str());
}

Window::~Window()
{
	for (std::pair<std::string, WindowItem*> _p : menus)
		delete _p.second; 
	menus.clear(); 
}
#pragma endregion constructor/destructor
#pragma region methods
LRESULT _stdcall Window::WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
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
		exit(0);
		break;
	}
	default:
		return DefWindowProcW(_hWindow, _msg, _wp, _lp);
	}
}

LRESULT _stdcall Window::WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	if (WM_NCCREATE == _msg)
	{
		SetWindowLongPtr(_hWindow, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lp)->lpCreateParams));
		return true;
	}
	return reinterpret_cast<Window*>(GetWindowLongPtr(_hWindow, GWLP_USERDATA))->WindowProc(_hWindow, _msg, _wp, _lp);
}

void Window::Update()
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

void Window::AddMenus(HWND _hwnd)
{
	const WindowItem* _menu = CreateWindowMenu("");
	WindowItem* _fichier = CreateWindowMenu("fichier"); 
	WindowItem* _outils = CreateWindowMenu("outils");
	_menu->CreatePopUp(_fichier); 
	_menu->CreatePopUp(_outils);
	SetMenu(_hwnd, *_menu); 

}

WindowItem* Window::CreateWindowMenu(std::string _name)
{
	WindowItem* _menu = new WindowItem(this, _name);
	menus.insert(std::pair<std::string, WindowItem*>(_name, _menu));
	return _menu; 
}

int Window::MenusCount() const
{
	return menus.size(); 
}

void Window::RegisterMenu(WindowItem* _menu)
{
	menus.insert(std::pair<std::string, WindowItem*>(_menu->Name(), _menu)); 
}

void Window::Open()
{
	if (windowInstance == nullptr) return; 
	isOpen = true; 
	ShowWindow(windowInstance, SW_SHOWDEFAULT);
	UpdateWindow(windowInstance);
	Update(); 
}

void Window::Close()
{
	CloseWindow(windowInstance); 
	isOpen = false; 
}
#pragma endregion methods



