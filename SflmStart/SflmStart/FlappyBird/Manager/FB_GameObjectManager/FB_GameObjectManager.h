#pragma once
#include "../../../Singleton/Singleton.h"
#include <vector>

class GameObject;

class FB_GameObjectManager : public Singleton<FB_GameObjectManager>
{
#pragma region f/p
private:
	std::vector<GameObject*> gameObjects = std::vector< GameObject*>();

#pragma endregion f/p
#pragma region constructor
public:
	FB_GameObjectManager() = default; 
#pragma endregion constructor
#pragma region methods
public:
	void Register(GameObject* _gameObject);
	void unRegister(GameObject* _gameObject);
	void Update(); 
	void Draw(class Window* _window);
	void CheckCollision();
#pragma endregion methods
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion override
};

