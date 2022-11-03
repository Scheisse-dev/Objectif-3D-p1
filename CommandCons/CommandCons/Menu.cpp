#pragma region commentZone
/*
* créer une map avec vecteur class name; et si map échoue throw exception
*/ 
#pragma endregion commentZone

#include "Menu.h"
#include <filesystem>

#pragma comment(lib, "version.lib")

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
	catch (const std::exception& _exception) // exception error log 
	{
		Utils::LogError(_exception.what());
	}
}

void Menu::DisplayItems()
{

	std::string _test;
	Utils::GetWindowsVersion();
	while (true) {
		std::string _path = std::filesystem::current_path().string();
		Utils::Replace(_path, '\\', '/');
		std::cout << _path << '>';
		//choose
		Utils::UserChoice();
		std::cout << std::endl;
	}

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

