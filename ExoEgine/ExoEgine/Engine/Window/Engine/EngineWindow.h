#pragma once
#include "../Window.h"

namespace Engine::Window
{
    class EngineWindow : public Window<EngineWindow>
    {
        DECLARE_CLASS_INFO(EngineWindow, Window<EngineWindow>)
#pragma region f/p
    private:
        sf::Clock clock = sf::Clock();
#pragma endregion f/p
#pragma region constructor
    public:
        EngineWindow();
#pragma endregion constructor
#pragma region override
    public:
        void Open() override;
        void OnUpdate() override;
        void OnClear() const override;
        void OnReceiveEvent(const sf::Event& _event) override;
#pragma endregion override
    };
}