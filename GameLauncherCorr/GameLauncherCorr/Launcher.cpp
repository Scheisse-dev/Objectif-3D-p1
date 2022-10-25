#include "Launcher.h"
#include "LauncherItem.h"
#include "Utils.h"
#include "IGame.h"

#pragma region constructor/destructor
Launcher::Launcher(const std::initializer_list<LauncherItem*> _items)
{
	for (LauncherItem* _item : _items)
		items.push_back(_item); 
}

Launcher::~Launcher()
{
	items.clear(); 
	delete currentGame; 
}
#pragma endregion constructor/destructor
#pragma region methods

void Launcher::Update()
{
	while (isOpen)
	{
		try
		{
			Utils::ClearConsole();

			DisplayItems(); 
			currentGameIndex = Utils::UserChoice<int>("Choose: ") - 1;
			if (currentGameIndex == items.size())
			{
				isOpen = false;
				continue; 
			}

			StartGame();

		}
		catch (const std::exception& _e)
		{
			Utils::LogError(_e.what());
			Utils::Pause();
			Utils::ClearConsole(); 
			Utils::LoadingBar("Error in " + currentGame->GameName() + ", closing game !"); 
		}
	}
	Utils::ClearConsole(); 
	Utils::LoadingBar("Quiting Launcher...");
}
void Launcher::StartGame()
{
	if (currentGameIndex < 0 || currentGameIndex > items.size())
		throw std::exception("[Launcher] => game index out of range !");
	LauncherItem* _item = items[currentGameIndex];
	currentGame = _item->Game();
	_item->Onclick();
}
void Launcher::DisplayItems()
{
	const size_t _size = items.size();
	for (size_t i = 0; i < _size; i++)
	{
		std::cout << std::to_string(i + 1) + ": ";
		items[i]->Display();
	}
}
void Launcher::Open()
{
	Update(); 
}
#pragma endregion methods
