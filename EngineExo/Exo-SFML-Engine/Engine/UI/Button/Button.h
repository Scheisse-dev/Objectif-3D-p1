#pragma once
#include <SFML/Graphics.hpp>
#include "../../Event/Action/ActionInternal.h"
#include "../../UI/Element/UIElement.h"
#include "../Interface/IPointerClickHandler.h"
#include "../Interface/IPointerEnterHandler.h"
#include "../Interface/IPointerExitHandler.h"

namespace Engine :: UI
{
    class Button : public UIElement, public IPointerClickHandler, public IPointerExitHandler, public IPointerEnterHandler
    {
        DECLARE_CLASS_INFO(Button, UIElement)
#pragma region val
    private:
        sf::Text text = sf::Text();
        float width = 100.0f;
        float height = 40.0f;
        sf::Color baseColor = sf::Color::White;
        sf::Color enterColor = sf::Color(189,195,199);
        Action<> onClick = nullptr;

#pragma endregion val
#pragma region const
    public:
        Button() = default;
        Button(const std::string& _text, float _width, float _height);
        Button(const std::string& _text, float _width, float _height, Action<> _onClick);
#pragma endregion 
#pragma region meth
    public:
        template<typename Class>
        void AddListener(Class* _instance, void(Class::* ptr)())
        {
            onClick.AddDynamic(_instance, ptr);
        }
        template<typename Class>
        void RemoveListener(Class* _instance, void(Class::* ptr)())
        {
            onClick.RemoveDynamic(_instance, ptr);
        }
        void SetBackgroundColor(const sf::Color& _color);
#pragma endregion
#pragma region override
    public:
        void SetPosition(const PrimaryType::Vector2& _position) override;
        void Draw(sf::RenderWindow* _window) override;
        void OnPointerClick(const sf::Event& _event) override;
        void OnPointerExit() override;
        void OnPointerEnter() override;
        void OnPointerUnClick() override {}
#pragma endregion

    };



}
