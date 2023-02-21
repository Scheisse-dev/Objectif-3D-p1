#include "Toggle.h"
#include "../../Manager/Texture/TextureManager.h"


#pragma region const
Engine::UI::Toggle::Toggle() : super()
{
    shape = new sf::RectangleShape(sf::Vector2f(40, 40));
    toggleFalseTexture = Manager::TextureManager::Instance()->GetTexture(TOGGLE_INVALID_NAME);
    toggleTrueTexture = Manager::TextureManager::Instance()->GetTexture(TOGGLE_VALID_NAME);
    shape->setTexture(toggleFalseTexture);
    shape->setFillColor(sf::Color::White);
}
Engine::UI::Toggle::Toggle(bool _status) : self()
{
    SetStatus(_status);
}
Engine::UI::Toggle::Toggle(const Toggle& _copy) : super(_copy)
{
    status = _copy.status;
    toggleFalseTexture = _copy.toggleFalseTexture;
    toggleTrueTexture = _copy.toggleTrueTexture;
    SetStatus(status);
}
#pragma endregion
#pragma region methods
bool Engine::UI::Toggle::Status()
{
    return status;
}
void Engine::UI::Toggle::SetStatus(bool _status)
{
    status = _status;
    shape->setTexture(status ? toggleTrueTexture : toggleFalseTexture);
}
#pragma endregion
#pragma region override
void Engine::UI::Toggle::OnPointerClick(const sf::Event& _event)
{
    SetStatus(!status);
}
#pragma endregion