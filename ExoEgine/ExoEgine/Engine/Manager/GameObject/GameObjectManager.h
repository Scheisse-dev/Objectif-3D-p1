#pragma once 

#include "../../Utils/Singleton/Singleton.h"

namespace Engine
{

	class GameObject;
}
namespace Engine::Manager
{
	class GameObjectManager : public Utils::Singleton<GameObjectManager>
	{
		DECLARE_CLASS_INFO(GameObjectManager, Singleton<GameObjectManager>)
#pragma region f/p
	private:
		std::vector<GameObject*> gameobjects = std::vector<GameObject*>();
#pragma endregion f/p
#pragma region constructor
	public:
		void Register(GameObject* _obj); 
		void UnRegister(GameObject* _obj);
		void Update() const;
		void OnDestroy();
#pragma endregion constructor
	};
}
