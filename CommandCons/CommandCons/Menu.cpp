#include "Menu.h"
#pragma region constructor/destructor

Menu::Menu(const std::string _title, std::initializer_list<MenuItem*> _item)
{
	title = _title;
	for (MenuItem* _item : _item)
		items.push_back(_item); 
}

Menu::Menu(const Menu& _copy)
{
	title = _copy.title;
	items = _copy.items; 
}
Menu::~Menu()
{
	items.clear(); 
}
#pragma endregion constructor/destructor

#pragma region methods

void Menu::Choose(const std::string _index)
{
	try //class name 
	{
		
	}
	catch(const std::exception& _exception) // exception error log 
	{
		Utils::LogError(_exception.what()); 
	}
}

void Menu::DisplayItems()
{
	Utils::ClearConsole(); 
	Utils::LogTitle(title); 
	const size_t _size = items.size(); 
	for (size_t i = 0; i < _size; i++)
		Utils::Log(std::to_string(i + 1) + ": " + items[i]->ToString());
	Utils::Log(std::to_string(_size + 1) + ": return"); 

}
std::vector<MenuItem*> Menu::Item() const
{
	return items; 
}
bool Menu::Equals(const Menu* _name)
{
	return title == _name->title; 
}

void Menu::SetOldMenu(Menu* _old)
{
	oldMenu = _old; 
}

Menu* Menu::OldMenu()
{
	return oldMenu;
}

void Menu::Close()
{
	isOpen = false; 
}

void Menu::Open()
{
	isOpen = true;
}


#pragma endregion methods 

