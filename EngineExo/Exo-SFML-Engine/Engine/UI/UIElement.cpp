#include "UIElement.h"

#pragma region const
Engine::UIElement::UIElement(const sf::Vector2f& _position)
{
    position = _position;    
}

Engine::UIElement::UIElement(const UIElement& _copy)
{
    position = _copy.position;
}

Engine::UIElement::~UIElement()
{}
#pragma endregion

#pragma region methods
sf::Vector2f Engine::UIElement::Position() const
{
    return position;
}

bool Engine::UIElement::IsInteractable() const
{
    return isInteractable;
}

void Engine::UIElement::SetPosition(const sf::Vector2f& _position)
{
    position = _position;
}

void Engine::UIElement::SetOrigin(const sf::Vector2f& _origin)
{}

void Engine::UIElement::SetScale(const sf::Vector2f& _scale)
{}

void Engine::UIElement::SetInteractable(bool _status)
{
    isInteractable = _status;
}

void Engine::UIElement::Draw(const Window::EngineWindow* _window) const
{}

sf::FloatRect Engine::UIElement::GetGlobalBounds()
{
    return sf::FloatRect();
}

void Engine::UIElement::Update()
{}
#pragma endregion
