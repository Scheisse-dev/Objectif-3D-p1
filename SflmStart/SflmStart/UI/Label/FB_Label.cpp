#include "FB_Label.h"
#include "SFML/Graphics.hpp"

#pragma region constructor/destructor
FB_Label::FB_Label(Window* _owner, const char* _text) : FB_UIElement(_owner)
{
	text = new sf::Text();
	text->setString(_text);
	font = new sf::Font(); 
	if (!font->loadFromFile("D:/GitHub/Objectif-3D-p1/SflmStart/Fonts/DeutscheZierschrift.ttf"))
	{
		Free();
		return;

	}
	text->setFont(*font);
}
FB_Label::~FB_Label()
{
	Free();
	return; 
}

void FB_Label::Free()
{
	delete text;
	text = nullptr;
	delete font;
	font = nullptr;
}


#pragma endregion constructor/destructor
#pragma region override
void FB_Label::SetText(const char* _text)
{
	text->setString(_text);
}
void FB_Label::SetCharacterSize(const int _size)
{
	text->setCharacterSize(_size);
}
void FB_Label::SetColor(const sf::Color& _color)
{
	text->setFillColor(_color);
}
void FB_Label::SetPosition(const sf::Vector2f& _position)
{
	text->setPosition(_position);
}
void FB_Label::SetScale(const sf::Vector2f& _scale)
{
	text->setScale(_scale); 
}

void FB_Label::Draw(Window* _window)
{
	if (text != nullptr)
		_window->Draw(text);
}

void FB_Label::SetOrigin(const sf::Vector2f& _origin)
{
	text->setOrigin(_origin);
}
sf::FloatRect FB_Label::GetGlobalBounds() const
{
	return text->getGlobalBounds();
}
#pragma endregion override 