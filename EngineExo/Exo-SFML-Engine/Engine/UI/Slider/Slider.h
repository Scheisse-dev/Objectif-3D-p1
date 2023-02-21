#pragma once
#include "../Element/UIElement.h"
#include "../../Event/Action/ActionInternal.h"
#include "../../UI/Interface/IPointerMoveHandler.h"

namespace Engine::UI
{
    class Slider : public UIElement, public IPointerMoveHandler
    {
        DECLARE_CLASS_INFO(Slider, UIElement)
#pragma region f/p
    private:
        sf::CircleShape* handle = nullptr; 
        sf::RectangleShape* box = nullptr;
        float minValue = 0.f;
        float maxValue = 100.f;
        float currentValue = 0.f;
        Action<float> onValueChanged = nullptr;
#pragma endregion
#pragma region const
    public:
        Slider();
        Slider(float _min, float _max, float _value);
        Slider(float _value);
        ~Slider() override;
#pragma endregion
#pragma region methods
    private:
        void UpdateHandlePosition();
    public:
        void SetValue(float _value);
        void SetMin(float _min);
        void Setmax(float _max);
        float GetValue();
#pragma endregion
#pragma region override
    public:
        void Draw(sf::RenderWindow* _window) override;
        void SetPosition(const PrimaryType::Vector2& _position) override;
        virtual void OnPointerMove(float _x, float _y) override;
#pragma endregion
    };
}





































//#include <SFML/Graphics.hpp>
//#include "../../Manager/UIElement/UIElementManager.h"
//#include "../../UI/UIElement.h"
//
//namespace Engine::UI
//{
//    class Slider : public UIElement
//    {
//        DECLARE_CLASS_INFO(Slider, UIElement)
//#pragma region f/p
//    private:
//        sf::RectangleShape* line = nullptr;
//        sf::CircleShape* cursor = nullptr;
//        sf::Text* currentValue = nullptr;
//        sf::Font* textFont = nullptr;
//        sf::Vector2f position = sf::Vector2f(50, 50);
//#pragma endregion
//#pragma region constru
//    public:
//        Slider();
//#pragma endregion
//#pragma region methods
//    public:
//        void Update(); 
//        void LineOnClick(const sf::RenderWindow& _window, sf::Mouse _mouse);
//        sf::Text* Value();
//        sf::RectangleShape* Line();
//        sf::CircleShape* Cursor(); 
//#pragma endregion
//    };
//
//}
