#include "LauncherItem.h"
#include "Utils.h"
#include "IGame.h"

LauncherItem::LauncherItem(IGame* _game)
{
	game = _game; 
}

LauncherItem::LauncherItem(const LauncherItem& _copy)
{
	game = _copy.game;
}

LauncherItem::~LauncherItem()
{
	delete game; 
}

void LauncherItem::Onclick()
{
	if (game == nullptr) throw std::exception("[Launcher Item] => current game is null !"); 
	Utils::ClearConsole(); 
	Utils::LoadingBar("Loading ");
	game->OnStart(); 
	game->DisplayMenu(); 
	game->OnUptdate();
	game->OnEnd(); 
}

void LauncherItem::Display()
{
	Utils::Log(game->GameName()); 
}

void LauncherItem::Game() const
{
	return game; 
}
