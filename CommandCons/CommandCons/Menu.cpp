#pragma region commentZone
/*
* créer une map avec vecteur class name; et si map échoue throw exception
*/ 
#pragma endregion commentZone

#include "Menu.h"
#include "Time.h"
#include "Echo.h"
#include "Task.h"
#include <filesystem>

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

void Menu::FonctionMix() //TODO replace if by map
{
	std::string _userChoice = Utils::UserChoice();
	//for (int i = 0; i < _userChoice.size(); i++)
	//{
	//	_userChoice = tolower(_userChoice[i]); 
	//}
	if (_userChoice == "echo")
	{
		Echo echo;
		echo.Out();
	}
	else if (_userChoice == "tasklist")
	{
		Task task;
		task.TaskList();
	}
	else if (_userChoice == "exit")
		isInLoop = false;
	else if (_userChoice == "cls")
		system("cls");
	else if (_userChoice == "time")
	{
		Time time;
		time.NowInternal();
	}

	
}

void Menu::Choose(const std::string _index)
{
	try //TODO try 
	{

	}
	catch (const std::exception& _exception) 
	{
		Utils::LogError(_exception.what());
	}
}

void Menu::DisplayItems()
{

	std::string _test;
	Utils::GetWindowsVersion();
	while (isInLoop) {						//TODO cancel this shit 
		std::string _path = std::filesystem::current_path().string();
		Utils::Replace(_path, '\\', '/');
		std::cout << _path << '>';
		Menu::FonctionMix();
	}

}
std::vector<MenuItem*> Menu::Item() const
{
	return items;
}


#pragma endregion methods 

