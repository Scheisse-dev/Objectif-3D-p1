#include "Menu.h"
#include "MenuItem.h"
#include "Utils.h"

#pragma region constructor/destructor
Menu::Menu(const std::string& _title, std::initializer_list<MenuItem*> _items)
{
	title = _title;
	for (MenuItem* _item : _items)
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
void Menu::Open()
{
	isOpen = true;
	DisplayItems();
}
void Menu::Close()
{
	isOpen = false;
}
void Menu::Update()
{
	int _index = -1;
	while (isOpen)
	{
		_index = Utils::UserChoice<int>() - 1;
		if (_index == items.size()) break;
		Choose(_index);
	}
	OpenOldMenu();
}
void Menu::OpenOldMenu()
{
	if (oldMenu != nullptr && oldMenu != this)
	{
		oldMenu->Open();
		Close();
	}
	else exit(0);
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

std::vector<MenuItem*> Menu::Items() const
{
	return items;
}

void Menu::Choose(const int _index)
{
	try
	{
		if (_index < 0 || _index > items.size())
			throw std::exception("[Menu] => index out of range !");
		items[_index]->OnClick(this);
	}
	catch (const std::exception& _exception)
	{
		Utils::LogError(_exception.what());
		Utils::Pause();
		OpenOldMenu();
	}
}

Menu* Menu::OldMenu() const
{
	return oldMenu;
}

void Menu::SetOldMenu(Menu* _old)
{
	oldMenu = _old;
}

bool Menu::Equals(const Menu* _other)
{
	return title == _other->title;
}
#pragma endregion methods