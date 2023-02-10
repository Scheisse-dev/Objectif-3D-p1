#pragma once
#include "../UIElement.h"

namespace Engine::UI
{
    class UI_Radio : public UIElement
    {
        DECLARE_CLASS_INFO(UI_Radio, UIElement)
#pragma region var
    private:
        sf::RectangleShape* rect = nullptr;
        bool checked = false;
#pragma endregion
#pragma region const
    public:
        UI_Radio() = default;
        UI_Radio(const sf::Vector2f& _position, bool _checked);
        ~UI_Radio() override;
#pragma endregion
#pragma region methods
    public:
        bool IsChecked() const;
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

