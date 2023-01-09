#include "FB_Game.h"
#include "../Menu/MainMenu/FB_MainMenu.h"
#include "../../UI/Button/FB_Button.h"
#include "../Manager/FB_GameObjectManager/FB_GameObjectManager.h"
#include "../Bird/FB_Bird.h"
#include <iostream>

#pragma region constructor/destructor
FB_Game::FB_Game() : Window(900, 500, "Flappy Bird")
{
	InitBackGround();
}

FB_Game::~FB_Game()
{
	delete background;
	background = nullptr;
}

#pragma endregion constructor/destructor
#pragma region methods 
void FB_Game::InitBackGround()
{
	background = new FB_Image(this, "D:/GitHub/Objectif-3D-p1/SflmStart/FlappyBird/background_flappybird.png");
	background->SetOrigin(sf::Vector2f(0, 0));
	background->SetScale(sf::Vector2f(3.0f, 3.5f));
}
void FB_Game::Start()
{
	CloseAllMenus();
	isStarted = true;
	bird = new FB_Bird();
}
#pragma endregion methods
#pragma region override
void FB_Game::OnDraw()
{
	background->Draw(this);
	for (std::pair<const char*, BaseMenu*> _pair : menus)
		_pair.second->Draw();
	if (!isStarted) return;
	FB_GameObjectManager::Instance()->Draw(this);
}
void FB_Game::OnUpdate()
{
	try
	{
		if (!isStarted) return;
			FB_GameObjectManager* _instance = FB_GameObjectManager::Instance();
			_instance->CheckCollision();
			_instance->Update();
	}
	catch (const std::exception& _e)
	{
		std::cout << _e.what() << std::endl;
	}
}
void FB_Game::InitMenu()
{

	FB_MainMenu* _mainMenu = new FB_MainMenu(this);
	_mainMenu->PlayButton()->OnClick.SetDynamic(this, &FB_Game::Start);
	_mainMenu->Open();
	RegisterMenu("main menu", _mainMenu);

}
#pragma endregion override



