#pragma once
#include "../../../Core/GameObject/GameObject.h"
#include "../../../Core/Gif/Gif.h"
#include "../../Entity/Entity.h"

namespace Game
{
	namespace Spell
	{
		class FireBall : public Core::GameObject
		{
			DECLARE_CLASS_INFO(FireBall, Core::GameObject)
#pragma region f/p
		private: 
			float speed = 100.0f;
			float lifeTime = 3.0f;
			float damage = 10.0f;
			Entity::Entity* owner = nullptr;
			Core::Gif* gif = nullptr;
			sf::Vector2f direction = sf::Vector2f(1, 0);
			sf::Clock clock = sf::Clock();
#pragma endregion f/p
#pragma region constructor/destructor
		public:
			FireBall(Entity::Entity* _owner);
			~FireBall() override;
#pragma endregion constructor/destructor
#pragma region methods
		public:
			void SetDirection(const sf::Vector2f& _direction);
			void SetDamage(const float _dmg);
#pragma endregion methods
#pragma region override
		public:
			void OnCollisionEnter(GameObject* _object) override; 
			void OnUpdate() override; 
#pragma endregion override
		};
	}
}