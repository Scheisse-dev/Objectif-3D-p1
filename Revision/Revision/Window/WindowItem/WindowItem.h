#pragma once
#include <string>
#include <Windows.h>

class Window; 

class WindowItem
{
#pragma region f/p 
private: 
	Window* handle = nullptr; 
	HMENU menu = nullptr; 
	std::string name = ""; 
#pragma endregion f/p
#pragma region constructor
public: 
	WindowItem() = default; 
	WindowItem(Window* _handle, std::string _name);
	WindowItem(const WindowItem& _copy); 
#pragma endregion constructor 
#pragma region methods
public:
	std::string Name() const; 
	void CreateButton(const std::string& _name);
	void CreateSeparator() const; 
	void CreatePopUp(const WindowItem* _subMenu) const; 
#pragma endregion methods
#pragma region operator
public:
	operator HMENU() const;
#pragma endregion operator
};

