#include "Slider.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include <iostream>

#pragma region const
Engine::UI::Slider::Slider()
{
    shape = new sf::RectangleShape(sf::Vector2f(150, 20));
    shape->setFillColor(sf::Color::Transparent);
    box = new sf::RectangleShape(sf::Vector2f(110, 4));
    box->setOrigin(shape->getOrigin());
    handle = new sf::CircleShape(8);
    handle->setOrigin(shape->getOrigin());
    SetValue(maxValue - minValue);
}

Engine::UI::Slider::Slider(float _min, float _max, float _value) : self()
{
    minValue = _min;
    maxValue = _max;
    currentValue = _value;
    SetValue(_value);
}

Engine::UI::Slider::Slider(float _value) : self( 0.f, 100.f, 100.f)
{
}


Engine::UI::Slider::Slider(const Slider& _copy) : super(_copy)
{
    shape = _copy.shape;
    box = _copy.box;
    minValue = _copy.minValue;
    maxValue = _copy.maxValue;
    currentValue = _copy.currentValue;
}
Engine::UI::Slider::~Slider()
{
    if (handle)
    {
        delete handle;
        handle = nullptr;
    }
    if (box)
    {
        delete box;
        box = nullptr;
    }

}
#pragma endregion
#pragma region methods
void Engine::UI::Slider::UpdateHandlePosition()
{
    const float _diff = maxValue - minValue;
    const float _diffNewValue = currentValue - minValue; 
    const float _t = box->getSize().x / _diff;
    const float _x = (_t * _diffNewValue) + shape->getPosition().x;
    handle->setPosition(sf::Vector2f(_x, handle->getPosition().y));
}

void Engine::UI::Slider::SetValue(float _value)
{
    currentValue = _value < minValue ? minValue : _value > maxValue ? maxValue : _value;
    onValueChanged.Invoke(currentValue);
    UpdateHandlePosition();
}

void Engine::UI::Slider::SetMin(float _min)
{
    minValue = _min;
}

void Engine::UI::Slider::Setmax(float _max)
{
    maxValue = _max;
}
#pragma endregion methods
#pragma region override
void Engine::UI::Slider::Draw(sf::RenderWindow* _window)
{
    if (handle == nullptr || box == nullptr) return;
    super::Draw(_window);
    _window->draw(*box);
    _window->draw(*handle);

}

void Engine::UI::Slider::SetPosition(const PrimaryType::Vector2& _position)
{
    super::SetPosition(_position);
    box->setPosition(_position);
    handle->setPosition(_position - sf::Vector2f(0, 5));
}

void Engine::UI::Slider::OnPointerMove(float _x, float _y)
{
    const float _newValue = minValue + (_x - shape->getPosition().x) / box->getSize().x * (maxValue - minValue);
    std::cout << _newValue << std::endl;
    SetValue(_newValue);
}

#pragma endregion override







































//#pragma region const
//Engine::UI::Slider::Slider()
//{
//    line = new sf::RectangleShape(sf::Vector2f(350, 5));
//    line->setFillColor(sf::Color::White);
//    line->setPosition(position);
//    cursor = new sf::CircleShape(10.f);
//    cursor->setFillColor(sf::Color::White);
//    cursor->setOrigin(sf::Vector2f(5.,6.));
//    cursor->setPosition(line->getPosition());
//    currentValue = new sf::Text();
//    textFont = new sf::Font();
//    currentValue->setColor(line->getFillColor());
//    textFont->loadFromFile("D:\\GitHub\\Objectif-3D-p1\\EngineExo\\Exo-SFML-Engine\\Asset\\EDITION_.ttf");
//    currentValue->setFont(*textFont);
//    currentValue->setPosition(sf::Vector2f(line->getPosition().x + 400, line->getPosition().y));
//    
//}
//Engine::UI::Slider::Slider(const Slider& _copy) : super(_copy)
//{
//}
//#pragma endregion 
//#pragma region methods
//void Engine::UI::Slider::Update()
//{
//
//}
//
//void Engine::UI::Slider::LineOnClick(const sf::RenderWindow& _window, sf::Mouse _mouse)
//{
//    // mouse pos intersec line.getGlobalBounds() && Event OnClick;
//    // get mouse position x 
//    // if(mouse posX > 0 , <100,)
//    // cursor.setposition(posX, 50);
//    
//    sf::FloatRect bounds = line->getGlobalBounds();
//
//    if (bounds.contains(_mouse.getPosition(_window).x, _mouse.getPosition(_window).y) && _mouse.isButtonPressed(sf::Mouse::Button::Left))
//    {
//        float posX = sf::Mouse::getPosition(_window).x;
//        if (posX > 50 && posX < 400)
//        {
//             int valueToShow = posX - 50;
//             cursor->setPosition(posX, 50);
//             currentValue->setString(std::to_string(valueToShow));
//        }
//    }
//}
//
//sf::Text* Engine::UI::Slider::Value()
//{
//    return currentValue;
//}
//
//sf::RectangleShape* Engine::UI::Slider::Line()
//{
//    return line;
//}
//
//sf::CircleShape* Engine::UI::Slider::Cursor()
//{
//    return cursor;
//}


//#pragma endregion

