#include "UI_Radio.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region const
Engine::UI::UI_Radio::UI_Radio(const sf::Vector2f& _position, bool _checked)
    : super(_position)
{
    rect = new sf::RectangleShape(sf::Vector2f(50.f, 50.f));
    drawable = rect;
    checked = _checked;
}

Engine::UI::UI_Radio::UI_Radio(const UI_Radio& _copy) : super(_copy)
{
    rect = _copy.rect;
    drawable = rect;
}

Engine::UI::UI_Radio::~UI_Radio()
{
    delete rect;
    rect = nullptr;
}
#pragma endregion

#pragma region methods
bool Engine::UI::UI_Radio::IsChecked() const
{
    return checked;
}
#pragma endregion

#pragma region override
sf::FloatRect Engine::UI::UI_Radio::GetGlobalBounds()
{
    return rect->getGlobalBounds();
}

void Engine::UI::UI_Radio::SetPosition(const sf::Vector2f& _position)
{
    rect->setPosition(_position);
}

void Engine::UI::UI_Radio::SetOrigin(const sf::Vector2f& _origin)
{
    rect->setOrigin(_origin);
}

void Engine::UI::UI_Radio::SetScale(const sf::Vector2f& _scale)
{
    rect->setScale(_scale);
}

void Engine::UI::UI_Radio::Draw(const Window::EngineWindow* _window) const
{
    if (rect == nullptr)
        return;
    rect->setPosition(Position());
    _window->Draw(rect);
}

void Engine::UI::UI_Radio::Update()
{}
#pragma endregion

