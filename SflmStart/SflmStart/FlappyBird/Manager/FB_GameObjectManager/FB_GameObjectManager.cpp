#include "FB_GameObjectManager.h"
#include "../../GameObject/GameObject.h"
#pragma region methods
void FB_GameObjectManager::Register(GameObject* _gameObject)
{
	gameObjects.push_back(_gameObject);
}

void FB_GameObjectManager::unRegister(GameObject* _gameObject)
{
	const size_t _size = gameObjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (gameObjects[i] == _gameObject)
		{
			gameObjects.erase(gameObjects.begin() + i);
			break;
		}
	}
}

void FB_GameObjectManager::Update()
{
	const size_t _size = gameObjects.size();
	for (size_t i = 0; i < _size; i++)
	{
			gameObjects[i]->OnUpdate();
	}
}

void FB_GameObjectManager::Destroy(GameObject* _gameObject)
{
	objectToDestroy.push_back(_gameObject);
}

void FB_GameObjectManager::Draw(Window* _window)
{
	const size_t _size = gameObjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		gameObjects[i]->OnDraw(_window);
	}

}
void FB_GameObjectManager::CheckCollision()
{
	for (GameObject* _a: gameObjects)
	{
		for (GameObject* _b : gameObjects)
		{
			if(_a ==_b || !_a->GetGlobalBounds().contains(_b->Position())) continue;
			_b->OnCollisionEnter(_a);
		}
	}
}
void FB_GameObjectManager::DestroyAllRequest()
{
	for (GameObject* _object : objectToDestroy)
	{
		unRegister(_object);
	}
	objectToDestroy.clear();
}
void FB_GameObjectManager::DestroyAllObjects()
{
	for (GameObject* _object : gameObjects)
	{
		delete _object;
		_object = nullptr;
	}
	objectToDestroy.clear();
	gameObjects.clear();
}
#pragma endregion methods
void FB_GameObjectManager::OnDestroy()
{
	const size_t _size = gameObjects.size();
	for (size_t i = 0; i < _size; i++)
	{
		delete gameObjects[i];
	}
	gameObjects.clear();
}
