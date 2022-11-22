#include "WindowMenu.h"
#include "Window.h"


#pragma region constructor
Core::WindowMenu::WindowMenu(Window* _handle, const char* _name)
{
	handle = _handle; 
	name = _name;
	menu = CreateMenu(); 
}

Core::WindowMenu::WindowMenu(const WindowMenu& _copy)
{
	handle = _copy.handle;
	name = _copy.name;
	menu = _copy.menu; 

}

#pragma endregion constructor

#pragma region methods

Core::PrimitiveType::FString Core::WindowMenu::Name() const
{
	return name; 
}
void Core::WindowMenu::CreateButtonMenu(const PrimitiveType::FString& _name)
{
	const int _key = handle->MenusCount() + 1; 
	AppendMenu(menu, MF_STRING, _key, _name.ToWString().c_str());
}
void Core::WindowMenu::CreateSeparator() const
{
	AppendMenu(menu, MF_SEPARATOR, -1, nullptr);
}
void Core::WindowMenu::CreatePopUpMenu(const WindowMenu* _subMenu) const
{
	const int _key = reinterpret_cast<UINT_PTR>(_subMenu->menu); 
	AppendMenu(menu, MF_POPUP, _key, _subMenu->Name().ToWString().c_str()); 
}

#pragma endregion methods
#pragma region operator
Core::WindowMenu::operator HMENU() const
{
	return menu;
}
#pragma endregion operator