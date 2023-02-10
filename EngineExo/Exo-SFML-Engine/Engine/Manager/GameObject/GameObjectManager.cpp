#include "GameObjectManager.h"
#include "../../GameObject/GameObject.h"
#include "../../Component/Component.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region const
Engine::Manager::GameObjectManager::GameObjectManager(const GameObjectManager& _copy)
{
    gameObjects = _copy.gameObjects;
}
#pragma endregion

#pragma region methods
void Engine::Manager::GameObjectManager::Register(GameObject* _obj)
{
    gameObjects.push_back(_obj);
}

void Engine::Manager::GameObjectManager::UnRegister(GameObject* _obj)
{
    for (size_t i = 0; i < gameObjects.size(); i++)
        if (gameObjects[i] == _obj)
        {
            delete gameObjects[i];
            gameObjects.erase(gameObjects.begin() + i);
        }
}

void Engine::Manager::GameObjectManager::Update()
{
    for (const GameObject* _gameObject : gameObjects)
    {
        for (Component* _compo : _gameObject->Components())
        {
            if (_compo == nullptr)
                continue;
            if (_compo->enabled)
            {
                Reflection::MethodsInfo<void>* _method = _compo->GetFunction<void>("Update");
                if (_method == nullptr)
                    continue;
                _method->Invoke(_compo);
            }
        }
    }
}

void Engine::Manager::GameObjectManager::Draw(const Window::EngineWindow* _window) const
{
    for (const GameObject* _obj : gameObjects)
        _obj->Draw(_window);
}

void Engine::Manager::GameObjectManager::OnDestroy()
{
    for (const GameObject* _gameObject : gameObjects)
    {
        delete _gameObject;
        _gameObject = nullptr;
    }
    gameObjects.clear();
}
#pragma endregion

