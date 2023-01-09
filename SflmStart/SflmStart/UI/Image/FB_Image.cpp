#include "FB_Image.h"


#pragma region constructor/destructor
FB_Image::FB_Image(Window* _owner, const char* _path) : FB_UIElement(_owner)
{
	sprite = new sf::Sprite(); 
	texture = new sf::Texture();
	if (!texture->loadFromFile(_path))
	{
		Free();
		return; 
	}
	sprite->setTexture(*texture);
}

FB_Image::FB_Image(const FB_Image& _copy)
{
	sprite = _copy.sprite;
	texture = _copy.texture;
}

FB_Image::~FB_Image()
{
	Free();
}

#pragma endregion constructor/destructor

#pragma region methods
void FB_Image::Free()
{
	delete sprite; 
	sprite = nullptr;
	delete texture;
	texture = nullptr; 
}
sf::FloatRect FB_Image::getGlobalBounds()
{
	return sprite->getGlobalBounds();
}
#pragma endregion methods

#pragma region override
void FB_Image::SetPosition(const sf::Vector2f& _position)
{
	sprite->setPosition(_position);

}

void FB_Image::SetScale(const sf::Vector2f& _scale)
{
	sprite->setScale(_scale); 
}

void FB_Image::Draw(Window* _window)
{
	if (sprite != nullptr)
		_window->Draw(sprite);
}

void FB_Image::SetOrigin(const sf::Vector2f& _origin)
{
	sprite->setOrigin(_origin);
}
sf::FloatRect FB_Image::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}
#pragma endregion override