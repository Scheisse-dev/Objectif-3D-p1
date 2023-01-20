#pragma once
#include "../../../Core/Window/Menu/BaseMenu.h"

namespace Game
{
#define QUIT_BUTTON_MAIN_MENU_PATH "quit_button"
#define PLAY_BUTTON_MAIN_MENU_PATH "play_button"
#define BACKGROUND_MAIN_PATH "background_main_menu"
#define TITLE_MAIN_MENU_PATH "title_main"

	class MainMenu : public Core::BaseMenu
	{
		DECLARE_CLASS_INFO(MainMenu, BaseMenu)
#pragma region f/p
	private:
		Core::UI::Image* background = nullptr;
		Core::UI::Image* title = nullptr; 
		Core::UI::Button* playButton = nullptr; 
		Core::UI::Button* quitButton = nullptr;
#pragma endregion f/p
#pragma region constructor
	public:
		MainMenu(Core::Window* _owner);
		MainMenu(const MainMenu& _copy);
#pragma endregion constructor
#pragma region methods
	public:
		void InitTitle();
		void InitPlayButton();
		void InitQuitButton();
		Core::UI::Button*& PlayButton();
		Core::UI::Button*& QuitButton();
#pragma endregion methods
#pragma region override
	public:
		void OnResize(const sf::Vector2f& _size) override;
#pragma endregion override
	};

}