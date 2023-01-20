#pragma once
#include "../../../../Core/Window/Menu/BaseMenu.h"
#include "../../../Entity/Mob/Mob.h"
#include "../../../Ground/Ground.h"
#include "../../../Entity/Player/Player.h"

namespace Game
{
#define BACKGROUND_GAME_PATH "background_game"
	class GameMenu : public Core::BaseMenu
	{
		DECLARE_CLASS_INFO(GameMenu, BaseMenu)

#pragma region f/p
	private:
		Core::UI::Image* background = nullptr;
		Entity::Mob* mob = nullptr;
		Ground* ground = nullptr;
		Player* player = nullptr;
#pragma endregion f/P
#pragma region constructor
	public:
		GameMenu(Core::Window* _owner);
		GameMenu(const GameMenu&) = delete; 
#pragma endregion constructor
#pragma region methods
	private:
		void Init(); 
#pragma endregion methods
#pragma region override
	public:
		void Open() override; 
		void OnResize(const sf::Vector2f& _size) override;
#pragma endregion override
	};

}