#include "UI_Label.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region const

Engine::UI::UI_Label::UI_Label(const sf::Vector2f& _position, sf::Font* _font, const std::string& _text)
    : super(_position)
{
    if (_font == nullptr)
        throw std::exception("[UI_Label] => font is nullptr");
    text = new sf::Text();
    text->setFont(*_font);
    text->setString(_text);
    drawable = text;
}

Engine::UI::UI_Label::UI_Label(const UI_Label& _copy) : super(_copy)
{
    text = _copy.text;
    drawable = text;
}

Engine::UI::UI_Label::~UI_Label()
{
    delete text;
    text = nullptr;
}
#pragma endregion

#pragma region methods
void Engine::UI::UI_Label::SetText(const std::string& _text)
{
    text->setString(_text);
}

void Engine::UI::UI_Label::SetFont(sf::Font* _font)
{
    if (_font != nullptr)
        text->setFont(*_font);
}

void Engine::UI::UI_Label::SetColor(sf::Color _color)
{
    text->setFillColor(_color);
}

void Engine::UI::UI_Label::SetCharactereSize(int _size)
{
    text->setCharacterSize(_size);
}
#pragma endregion

#pragma region override
sf::FloatRect Engine::UI::UI_Label::GetGlobalBounds()
{
    return text->getGlobalBounds();
}

void Engine::UI::UI_Label::SetPosition(const sf::Vector2f& _position)
{
    text->setPosition(_position);
}

void Engine::UI::UI_Label::SetOrigin(const sf::Vector2f& _origin)
{
    text->setOrigin(_origin);
}

void Engine::UI::UI_Label::SetScale(const sf::Vector2f& _scale)
{
    text->setScale(_scale);
}

void Engine::UI::UI_Label::Draw(const Window::EngineWindow* _window) const
{
    if (text == nullptr)
        return;
    text->setPosition(Position());
    _window->Draw(text);
}

void Engine::UI::UI_Label::Update()
{}
#pragma endregion

