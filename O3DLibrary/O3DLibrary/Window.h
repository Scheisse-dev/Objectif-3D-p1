#pragma once
#include <Windows.h>
#include <map>
#include "FString.h"
#include "Object.h"

namespace Core
{
	class WindowMenu;

	class Window : public Object
	{
#pragma region f/p
	private:
		HWND windowInstance = nullptr; 
		PrimitiveType::FString name = "";
		int width = 1920;
		int height = 1080;
		bool isOpen = true; 
		std::map<const char*, WindowMenu*> menus = std::map<const char*, WindowMenu*>();
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
		O3DLIBRARY_API int MenusCount() const;
		O3DLIBRARY_API void RegisterMenu(WindowMenu* _menu);
		O3DLIBRARY_API void Open();
		O3DLIBRARY_API void Close();
#pragma endregion methods
	};
}
