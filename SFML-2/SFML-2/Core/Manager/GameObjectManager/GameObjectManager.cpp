#include "GameObjectManager.h"
#include "../../GameObject/GameObject.h"
#include "../../Window/Window.h"

void Core::Manager::GameObjectManager::CheckCollision()
{
	for (GameObject* _a : gameObjects)
	{
		for (GameObject* _b : gameObjects)
		{
			if (_a = _b) continue;
			if (_a->GlobalBounds().intersects(_b->GlobalBounds()))
			{
				std::vector<GameObject*>& _collideObject = _b->CollidedObject();
				if (std::ranges::find(_collideObject, _a) == _collideObject.end())
				{
					_collideObject.push_back(_a);
					_b->OnCollisionEnter(_a);
				}
			}
			else
			{
				std::vector<GameObject*>& _collidedObject = _b->CollidedObject();
			const std::vector<GameObject*>::iterator& _index = std::ranges::find(_collidedObject, _a);
			if (_index != _collidedObject.end())
			{
				_collidedObject.erase(_index);
				_b->OnCollisionEnter(_a);
			}
			}
		}
	}
}

void Core::Manager::GameObjectManager::Destroy(GameObject* _item)
{
	requestedDestroyObject.push_back(_item);
}

void Core::Manager::GameObjectManager::Register(GameObject* item)
{
	gameObjects.push_back(item);
}

void Core::Manager::GameObjectManager::UnRegister(GameObject* item)
{
	std::erase(gameObjects, item);
}

void Core::Manager::GameObjectManager::DestroyAllRequest()
{
	for (GameObject*& _object : requestedDestroyObject)
	{
		delete _object;
		_object = nullptr;
	}
}

void Core::Manager::GameObjectManager::Update()
{
	CheckCollision();
	const std::vector<GameObject*> objects = gameObjects;
	for (GameObject* object : objects)
		object->OnUpdate();
}

void Core::Manager::GameObjectManager::Draw(Core::Window* _window)
{
	const std::vector<GameObject*> objects = gameObjects;
	for (GameObject* object : objects)
	object->Draw(_window);
}

void Core::Manager::GameObjectManager::OnDestroy()
{
	for (GameObject*& gameobject : gameObjects)
	{
		if (gameobject == nullptr) continue;
		delete gameobject;
		gameobject = nullptr;
	}
	gameObjects.clear();
	requestedDestroyObject.clear();
}
