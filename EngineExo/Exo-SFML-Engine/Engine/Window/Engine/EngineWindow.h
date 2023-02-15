#pragma once
#include "../Window.h"
#include "../../UI/Element/UIElement.h"


namespace Engine::UI
{
    class UIELement;
    class Button;
    class Slider;
    class Toggle;
}




namespace Engine::Window
{
    class EngineWindow : public Window<EngineWindow>
    {
        DECLARE_CLASS_INFO(EngineWindow, Window<EngineWindow>)
#pragma region f/p
    private:
        sf::Mouse mouse = sf::Mouse();
        std::map<std::string, UI::UIElement*> elements = std::map<std::string, UI::UIElement*>();
        sf::Clock clock = sf::Clock();
#pragma endregion f/p
#pragma region const
    public:
        EngineWindow();
#pragma endregion const
#pragma region override
    public:
        void Test();
        void Open() override;
        void OnUpdate() override;
        void OnClear() const override;
        void OnReceiveEvent(const sf::Event& _event) override;
#pragma endregion override
    };
}
