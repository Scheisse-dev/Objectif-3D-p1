#pragma once
#include "../../../Core/GameObject/GameObject.h"
#include "../Entity.h";
namespace Game
{
	
	class Player : public Entity::Entity
	{
		DECLARE_CLASS_INFO(Player, Entity);
#pragma region f/p
		float jumpForce = 100.0f;
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