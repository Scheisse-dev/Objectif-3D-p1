#pragma once
#include "Object.h"

class Menu; 

class MenuItem: public Object
{
#pragma region f/p
private: 
	std::string name = ""; 
	Menu* nextMenu = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public: 
	MenuItem() = default; 
	MenuItem(const std::string _name, Menu* _owner); 
	MenuItem(const MenuItem& _copy) = default;
	~MenuItem() override = default; 
#pragma endregion constructor/destructor
#pragma region methods
public: 
	std::string Name(); 
	void OnClick(Menu* _currentMenu); 
	Menu* NextMenu() const; 
#pragma endregion methods
#pragma region override
public: 
	std::string ToString() const override; 
#pragma endregion override
};

