#pragma once
#include "../../../Core/GameObject/GameObject.h"
#include "../Entity.h";
#include "../../Spell/Base/BaseSpell.h"
#include "../../../Core/Input/Input.h"

namespace Game
{
	
	class Player : public Entity::Entity
	{
		DECLARE_CLASS_INFO(Player, Entity);
#pragma region f/p
		float jumpForce = 100.0f;
		std::map<Core::EKey, Spell::BaseSpell*> spells = std::map<Core::EKey, Spell::BaseSpell*>();
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		Player();
		Player(const Player& _copy);
		~Player();
#pragma endregion constructor/destructor
#pragma region override
	public:
		void OnUpdate() override;
		void OnCollisionEnter(GameObject* _object) override; 
#pragma endregion override
	};

}