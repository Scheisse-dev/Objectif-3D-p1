#include "Label.h"
#include "../../Manager/FontManager.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../PrimaryType/String/String.h"

#pragma region const
Engine::UI::Label::Label()
{
    text.setFont(*Manager::FontManager::Instance()->GetFont("Arial"));
    text.setCharacterSize(12);
    text.setString("");
    Manager::EventSystem::Instance()->Register(this);
}

Engine::UI::Label::Label(const char* _text, int _charactersSize, const char* _fontName)
{
    text.setString(_text);
    text.setCharacterSize(_charactersSize);
    text.setFont(*Manager::FontManager::Instance()->GetFont(_fontName));
}
Engine::UI::Label::Label(const Label&) = default;

#pragma endregion
#pragma region meth
void Engine::UI::Label::SetFont(const char* _fontName)
{
    text.setFont(*Manager::FontManager::Instance()->GetFont(_fontName));
}

void Engine::UI::Label::SetCharacterSize(int _value)
{
    text.setCharacterSize(_value);
}

void Engine::UI::Label::SetColor(const sf::Color& _color)
{
    text.setColor(_color);
}
#pragma endregion
#pragma region override
void Engine::UI::Label::SetPosition(const PrimaryType::Vector2& _position)
{
    text.setPosition(_position);
}

void Engine::UI::Label::SetRotation(const float _rotation)
{
    text.setRotation(_rotation);
}

void Engine::UI::Label::SetScale(const PrimaryType::Vector2& _scale)
{
    text.setScale(_scale);
}

void Engine::UI::Label::SetOrigin(const PrimaryType::Vector2& _position)
{
    text.setOrigin(_position);
}

void Engine::UI::Label::SetLabel(const char* _label)
{
    text.setString(_label);
}


Engine::PrimaryType::Vector2 Engine::UI::Label::Position() const
{
    return PrimaryType::Vector2();
}

sf::Shape* Engine::UI::Label::Shape() const
{
    return nullptr;
}

float Engine::UI::Label::Rotation() const
{
    return 0.0f;
}

Engine::PrimaryType::Vector2 Engine::UI::Label::Scale() const
{
    return text.getScale();
}

Engine::PrimaryType::Vector2 Engine::UI::Label::Origin() const
{
    return text.getOrigin();
}
Engine::PrimaryType::String Engine::UI::Label::LabelText() const
{
    return text.getString().toAnsiString().c_str();
}
void Engine::UI::Label::Draw(sf::RenderWindow* _window)
{
    _window->draw(text);
}
#pragma endregion