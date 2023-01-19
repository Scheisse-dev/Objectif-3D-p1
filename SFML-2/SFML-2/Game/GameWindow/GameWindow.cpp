#include "GameWindow.h"
#include "Menu/MainMenu.h"

#pragma region constructor
Game::GameWindow::GameWindow() : super (900, 800 , "Rpg Game")
{
	MainMenu* _mainMenu = new MainMenu(this);
	RegisterMenu("main", _mainMenu);
	OpenMenu("main");
}
#pragma endregion constructor
#pragma region methods
void Game::GameWindow::StartGame()
{
	OpenMenu("game");
	//TODO add to menu database
}
#pragma endregion methods