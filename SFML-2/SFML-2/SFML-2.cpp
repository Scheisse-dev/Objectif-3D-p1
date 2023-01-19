#include <iostream>

#include "Core/Input/Input.h"
#include "Core/Manager/Font/FontManager.h"
#include "Core/Manager/GameObjectManager/GameObjectManager.h"
#include "Core/Manager/TextureManager/TextureManager.h"
#include "Game/GameWindow/GameWindow.h"
int main()
{
	Core::Input::Init();
	Core::Manager::FontManager::Instance()->Init();
	Core::Manager::TextureManager::Instance()->Init();
	//Game Window
	//End
	Game::GameWindow _gameWindow = Game::GameWindow();
	_gameWindow.Open();
	//Core::Manager::GameObjectManager::Instance()->Destroy();
}
