#include "AssetButton.h"
#include <SFML/Graphics.hpp>

#include "../../Manager/FontManager.h"
#include "../../PrimaryType/Vector2/Vector2.h"

#pragma region const
Engine::UI::AssetButton::AssetButton(const std::string& _text, float _width, float _height, Object* _obj, const Action<Object*>& _onClick) : super()
{
    width = _width;
    height = _height;
    shape = new sf::RectangleShape(PrimaryType::Vector2(width, height));
    text.setString(_text);
    text.setFont(*Manager::FontManager::Instance()->GetFont("Arial"));
    text.setCharacterSize(12);
    text.setOrigin(shape->getOrigin());
    text.setFillColor(sf::Color::Black);
    OnClick = _onClick;
    object = _obj;
}

Engine::UI::AssetButton::AssetButton(const AssetButton& _copy) : super(_copy)
{
    width = _copy.width;
    height = _copy.height;
    text = _copy.text;
    baseColor = _copy.baseColor;
    enterColor = _copy.enterColor;
    OnClick = _copy.OnClick;
    object = _copy.object;
}


#pragma endregion
#pragma region methods
void Engine::UI::AssetButton::SetBackgroundColor(const sf::Color& _color)
{
    checkLow((shape != nullptr), "shape is nullptr !");
    baseColor = _color;
    shape->setFillColor(baseColor);
}

#pragma endregion
#pragma region override
void Engine::UI::AssetButton::OnPointerClick(const sf::Event& _event)
{
    checkLow((shape != nullptr), "shape is nullptr !");
    if (!canInteract) return;
    OnClick.Invoke(object);
}

void Engine::UI::AssetButton::OnPointerUnClick() { }

void Engine::UI::AssetButton::OnPointerEnter()
{
    checkLow((shape != nullptr), "shape is nullptr !");
    if (!canInteract) return;
    shape->setFillColor(enterColor);
}

void Engine::UI::AssetButton::OnPointerExit()
{
    checkLow((shape != nullptr), "shape is nullptr !");
    if (!canInteract) return;
    shape->setFillColor(baseColor);
}

void Engine::UI::AssetButton::SetPosition(const PrimaryType::Vector2& _position)
{
    super::SetPosition(_position);
    const sf::FloatRect _shapeBounds = shape->getGlobalBounds();
    const sf::FloatRect _textBounds = text.getGlobalBounds();
    const float _x = _shapeBounds.left + (_shapeBounds.width / 2) - (_textBounds.width / 2);
    const float _y = _shapeBounds.top + (_shapeBounds.height / 2) - (_textBounds.height / 2);
    text.setPosition(_x, _y);
}

void Engine::UI::AssetButton::Draw(sf::RenderWindow* _window)
{
    super::Draw(_window);
    _window->draw(text);
}
#pragma endregion