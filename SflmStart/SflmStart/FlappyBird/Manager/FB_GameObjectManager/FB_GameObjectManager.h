#pragma once
#include "../../../Singleton/Singleton.h"
#include <vector>

class GameObject;

class FB_GameObjectManager : public Singleton<FB_GameObjectManager>
{
#pragma region f/p
private:
	std::vector<GameObject*> gameObjects = std::vector< GameObject*>();
	std::vector<GameObject*> objectToDestroy = std::vector<GameObject*>();
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
	void Destroy(GameObject* _gameObject);
	void Draw(class Window* _window);
	void CheckCollision();
	void DestroyAllRequest();
	void DestroyAllObjects();
#pragma endregion methods
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion override
};

