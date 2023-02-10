#pragma once
#include "../../Utils/Singleton/Singleton.h"

namespace Engine
{
    class GameObject;

    namespace Window
    {
        class EngineWindow;
    }
}

namespace Engine::Manager
{
    class GameObjectManager : public Engine::Utils::Singleton<GameObjectManager>
    {
        DECLARE_CLASS_INFO(GameObjectManager, Singleton<GameObjectManager>)
#pragma region var
    private:
        std::vector<Engine::GameObject*> gameObjects = std::vector<Engine::GameObject*>();
#pragma endregion
#pragma region const
    public:
        GameObjectManager() = default;
#pragma endregion
#pragma region methods
    public:
        void Register(GameObject* _obj);
        void UnRegister(GameObject* _obj);
        void Update();
        void Draw(const Window::EngineWindow* _window) const;
        void OnDestroy() override;
#pragma endregion

    };
}
