#include "MainMenu.h"
#include "../../../Core/UI/Image/Image.h"
#include "../../../Core/Window/Window.h"

#pragma region constructor
Game::MainMenu::MainMenu(Core::Window* _owner) : super(_owner)
{
	//background
	background = CreateImage(sf::Vector2f(0, 0), BACKGROUND_MAIN_PATH);
	checkLow((background != nullptr && background->IsValid()), "[MainMenu] => background is nullptr or not valid !")
	background->SetOrigin(sf::Vector2f(0, 0));
	background->SetScale(sf::Vector2f(owner->Width() / background->GlobalBounds().width, owner->Height() / background->GlobalBounds().height));


	//title
	title = CreateImage(sf::Vector2f(owner->Width() / 2, 80), TITLE_MAIN_MENU_PATH);
	checkLow((title != nullptr && title->IsValid()), "[MainMenu] => title is nullptr or not valid !")
	title->SetOrigin(sf::Vector2f( title->GlobalBounds().width / 2, title->GlobalBounds().height / 2));
	title->SetScale(sf::Vector2f(0.5f, 0.5f));
}

Game::MainMenu::MainMenu(const MainMenu& _copy) : super (_copy)
{
	background = _copy.background;
	title = _copy.title;
}
#pragma endregion constructor
#pragma region override
void Game::MainMenu::OnResize(const sf::Vector2f& _size)
{
	background->SetScale(sf::Vector2f(_size.x / background->GlobalBounds().width, _size.y / background->GlobalBounds().height));
	title->SetPosition(sf::Vector2f(_size.x / 2, 80));
}
#pragma endregion override