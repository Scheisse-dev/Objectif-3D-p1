#pragma once
#include "../../../Core/Object/Object.h"
#include "../../../Core/Gif/Gif.h"
#include "../../Entity/Entity.h"
namespace Game
{
	namespace Spell
	{
		class BaseSpell : public Core::Object
		{
			DECLARE_CLASS_INFO(BaseSpell, Object)
#pragma region f/p
		private:
			std::string name = "Default spell name";
			float cooldown = 5.0f;
			float manaCost = 1.0f;
			float currentCooldown = 0.0f;
		protected:
			Entity::Entity* owner = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
		public:
			BaseSpell(const char* _name);
#pragma endregion constructor/destructor
#pragma region methods
		protected:
			bool IsInCooldown() const;
			float Cooldown() const; 
			float ManaCost() const; 
			std::string Name() const;
			Entity::Entity* Owner() const;
		public:
			virtual void OnUse() = 0;
#pragma endregion methods
		};
	}
}