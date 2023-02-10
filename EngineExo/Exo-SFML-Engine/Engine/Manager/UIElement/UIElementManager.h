#pragma once
#include "../../Utils/Singleton/Singleton.h"

namespace Engine
{
    class UIElement;

    namespace Window
    {
        class EngineWindow;
    }
}

namespace Engine::Manager
{
    class UIElementManager : public Engine::Utils::Singleton<UIElementManager>
    {
        DECLARE_CLASS_INFO(UIElementManager, Singleton<UIElementManager>)
#pragma region var
    private:
        std::vector<Engine::UIElement*> elements = std::vector<Engine::UIElement*>();
#pragma endregion
#pragma region const
    public:
        UIElementManager() = default;
#pragma endregion
#pragma region methods
    public:
        void Register(UIElement* _obj);
        void UnRegister(UIElement* _obj);
        void Update();
        void Draw(const Window::EngineWindow* _window) const;
        void OnDestroy() override;
#pragma endregion

    };
}
