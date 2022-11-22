#pragma once
#include <Windows.h>
#include "FString.h"

namespace Core
{
	class Window
	{
#pragma region f/p
	private:
		HWND windowInstance = nullptr; 
		PrimitiveType::FString name = "";
		int width = 1920;
		int height = 1080;
		bool isOpen = true; 
#pragma endregion f/p
#pragma region constructor
	public: 
		O3DLIBRARY_API Window() = default;
		O3DLIBRARY_API Window(const PrimitiveType::FString& _name, const int _width, const int _height);
#pragma endregion constructor
#pragma region methods
	private: 
		O3DLIBRARY_API LRESULT _stdcall WindowProc(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
		O3DLIBRARY_API static LRESULT _stdcall WindowProc_Internal(HWND _hWindow, UINT _msg, WPARAM _wp, LPARAM _lp);
	protected: 
		O3DLIBRARY_API virtual void Update();
		O3DLIBRARY_API virtual void AddMenus(HWND _hwnd);
	public: 
		O3DLIBRARY_API void Open();
		O3DLIBRARY_API void Close();
#pragma endregion methods
	};
}
