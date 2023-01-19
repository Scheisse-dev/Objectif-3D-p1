#pragma once
#include "../../../Core/GameObject/GameObject.h"

namespace Game
{
	namespace Interface
	{
		class IInteractable : public Core::GameObject
		{
			DECLARE_CLASS_INFO(IInteractable, GameObject)
#pragma region constructor/destructor
		public:
			IInteractable();
			~IInteractable() override;
#pragma endregion constructor/destructor
#pragma region methods
		public:
			virtual void OnInteract(class Player* _player) = 0;
#pragma endregion methods
		};
	}
}