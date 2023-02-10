#pragma once
#include "../Window.h"
#include "../../UI/UIElement.h"

namespace Engine::Window
{
    class EngineWindow : public Window<EngineWindow>
    {
        DECLARE_CLASS_INFO(EngineWindow, Window<EngineWindow>)
#pragma region var
    private:
        std::map<std::string, UIElement*> elements = std::map<std::string, UIElement*>();
        sf::Clock clock = sf::Clock();
#pragma endregion
#pragma region const
    public:
        EngineWindow();
#pragma endregion
#pragma region override
    public:
        void Open() override;
        void OnUpdate() override;
        void OnClear() const override;
        void OnReceiveEvent(const sf::Event& _event) override;
#pragma endregion
    };
}
