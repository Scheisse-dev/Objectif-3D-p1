#pragma once
#include "../UIElement.h"

namespace Engine::UI
{
    class UI_Shape : public UIElement
    {
        DECLARE_CLASS_INFO(UI_Shape, UIElement)
#pragma region var
    private:
        sf::Shape* shape = nullptr;
#pragma endregion
#pragma region const
    public:
        UI_Shape() = default;
        UI_Shape(const sf::Vector2f& _position, sf::Shape* _shape);
        ~UI_Shape() override;
#pragma endregion
#pragma region override
    public:
        sf::FloatRect GetGlobalBounds() override;
        void SetPosition(const sf::Vector2f& _position) override;
        void SetOrigin(const sf::Vector2f& _origin) override;
        void SetScale(const sf::Vector2f& _scale) override;
        void Draw(const Window::EngineWindow* _window) const override;
        void Update() override;
#pragma endregion
    };
}
