#include "UI_Shape.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region const
Engine::UI::UI_Shape::UI_Shape(const sf::Vector2f& _position, sf::Shape* _shape)
    : super(_position)
{
    shape = _shape;
    drawable = shape;
}

Engine::UI::UI_Shape::UI_Shape(const UI_Shape& _copy) : super(_copy)
{
    shape = _copy.shape;
    drawable = shape;
}

Engine::UI::UI_Shape::~UI_Shape()
{
    delete shape;
    shape = nullptr;
}
#pragma endregion

#pragma region override
sf::FloatRect Engine::UI::UI_Shape::GetGlobalBounds()
{
    return shape->getGlobalBounds();
}

void Engine::UI::UI_Shape::SetPosition(const sf::Vector2f& _position)
{
    shape->setPosition(_position);
}

void Engine::UI::UI_Shape::SetOrigin(const sf::Vector2f& _origin)
{
    shape->setOrigin(_origin);
}

void Engine::UI::UI_Shape::SetScale(const sf::Vector2f& _scale)
{
    shape->setScale(_scale);
}

void Engine::UI::UI_Shape::Draw(const Window::EngineWindow* _window) const
{
    if (shape == nullptr)
        return;
    shape->setPosition(Position());
    _window->Draw(shape);
}

void Engine::UI::UI_Shape::Update()
{}
#pragma endregion

