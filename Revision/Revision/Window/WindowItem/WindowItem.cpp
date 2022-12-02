#include "WindowItem.h"
#include "..\..\Object\Object.h"
#include "..\Window.h"

#pragma region constructor
WindowItem::WindowItem(Window* _handle, std::string _name)
{
	handle = _handle; 
	name = _name;
	menu = CreateMenu(); 
}

WindowItem::WindowItem(const WindowItem& _copy)
{
	handle = _copy.handle;
	name = _copy.name;
	menu = _copy.menu; 
}

#pragma endregion constructor
#pragma region methods
std::string WindowItem::Name() const
{
	return name; 
}

void WindowItem::CreateButton(const std::string& _name)
{
	const int _key = handle->MenusCount(); 
	std::wstring Wname = std::wstring(_name.begin(), _name.end()); 
	AppendMenu(menu, MF_STRING, _key, Wname.c_str()); 

}
void WindowItem::CreateSeparator() const
{
	AppendMenu(menu, MF_SEPARATOR, -1, nullptr); 
}
void WindowItem::CreatePopUp(const WindowItem* _subMenu) const
{
	std::string _name = _subMenu->Name();

	std::wstring Wname = std::wstring(_name.begin(), _name.end());
	const int _key = reinterpret_cast<UINT_PTR>(_subMenu->menu);
	AppendMenu(menu, MF_POPUP, _key, Wname.c_str()); 
}

#pragma endregion methods
#pragma region operator
WindowItem::operator HMENU() const
{
	return menu; 
}

#pragma endregion operator
