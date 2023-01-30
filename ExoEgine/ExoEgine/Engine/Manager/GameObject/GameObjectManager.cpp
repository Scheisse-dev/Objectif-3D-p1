#include "GameObjectManager.h"
#include "../../GameObject/GameObject.h"

void Engine::Manager::GameObjectManager::Register(GameObject* _obj)
{
	gameobjects.push_back(_obj);
}

void Engine::Manager::GameObjectManager::UnRegister(GameObject* _obj)
{
	std::erase(gameobjects, _obj);
}

void Engine::Manager::GameObjectManager::Update() const
{
	for (GameObject* _gameobject : gameobjects)
	{
		for (Component* _component : _gameobject->Components())
		{
			if (_component->enable)
			{
				Reflection::MethodsInfo<void>* _method = _component->GetFunction<void>("Update");
				if (_method == nullptr) continue;
				_method->Invoke(_component);
			}
		}
	}
}

void Engine::Manager::GameObjectManager::OnDestroy()
{
	for (GameObject*& _gameobject : gameobjects)
	{
		delete _gameobject;
		_gameobject = nullptr;
	}
	gameobjects.clear();
}
