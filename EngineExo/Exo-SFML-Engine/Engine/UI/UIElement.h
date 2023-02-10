#pragma once
#include "../Object/Object.h"
#include "SFML/Graphics.hpp"

namespace Engine
{
    namespace Window
    {
        class EngineWindow;
    }

    class UIElement : public Object
    {
        DECLARE_CLASS_INFO(UIElement, Object)
#pragma region var
    private:
        sf::Vector2f position = sf::Vector2f(0.f, 0.f);
        bool isInteractable = false;
    protected:
        sf::Drawable* drawable = nullptr;
#pragma endregion
#pragma region const/dest
    public:
        UIElement() = default;
        UIElement(const sf::Vector2f& _position);
        virtual ~UIElement() override;
#pragma endregion
#pragma region methods
    public:
        sf::Vector2f Position() const;
        bool IsInteractable() const;

        void SetInteractable(bool _status);
        virtual void Draw(const Window::EngineWindow* _window) const;
        virtual sf::FloatRect GetGlobalBounds();
        virtual void SetPosition(const sf::Vector2f& _position);
        virtual void SetOrigin(const sf::Vector2f& _origin);
        virtual void SetScale(const sf::Vector2f& _scale);
        virtual void Update();
#pragma endregion
    };
}
