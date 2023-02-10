#pragma once
#include "../UIElement.h"
#include <string>

namespace Engine::UI
{
    class UI_Label : public UIElement
    {
        DECLARE_CLASS_INFO(UI_Label, UIElement)
#pragma region var
    private:
        sf::Text* text = nullptr;
#pragma endregion
#pragma region const
    public:
        UI_Label() = default;
        UI_Label(const sf::Vector2f& _position, sf::Font* _font, const std::string& _text);
        ~UI_Label() override;
#pragma endregion
#pragma region methods
    public:
        void SetText(const std::string& _text);
        void SetFont(sf::Font* _font);
        void SetColor(sf::Color _color);
        void SetCharactereSize(int _size);
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

