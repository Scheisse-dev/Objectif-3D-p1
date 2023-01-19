#pragma once
#include <vector>

#include "../../Utils/Singleton/Singleton.h"

namespace Core
{
	class GameObject;
	class Window;
	namespace Manager
	{
		class GameObjectManager : public Utils::Singleton<GameObjectManager>
		{
			DECLARE_CLASS_INFO(GameObjectManager, Singleton<GameObjectManager>)

#pragma region f/p
		private:
			std::vector<GameObject*> gameObjects = std::vector<GameObject*>();
			std::vector<GameObject*> requestedDestroyObject = std::vector<GameObject*>();
#pragma endregion f/p
#pragma region methods
		private:
			void CheckCollision();
		public:
			void Destroy(GameObject* _item);
			void Register(GameObject* item);
			void UnRegister(GameObject* item);
			void DestroyAllRequest();
			void Update();
			void Draw(Core::Window* _window);
			void OnDestroy() override;
#pragma endregion methods
		};
	}
}