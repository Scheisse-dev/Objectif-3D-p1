#include "Ground.h"
#include "../../Core/Window/Window.h"
#include "../../Core/Utils/Debug/Debug.h"

#pragma region constructor
Game::Ground::Ground(const sf::Vector2f& _size, const sf::Color& _color)
{
	rectangleShape = new sf::RectangleShape(_size);
	rectangleShape->setFillColor(_color);
}

#pragma endregion constructor
#pragma region override
void Game::Ground::Draw(Core::Window* _window)
{
	checkLow((rectangleShape != nullptr), "[Ground] => rectangleShape is nullptr !");
	_window->Draw(rectangleShape);
}

void Game::Ground::SetPosition(const sf::Vector2f& _position)
{
	checkLow((rectangleShape != nullptr), "[Ground] => rectangleShape is nullptr !");
	rectangleShape->setPosition(_position);
}

void Game::Ground::SetOrigin(const sf::Vector2f& _origin)
{
	checkLow((rectangleShape != nullptr), "[Ground] => rectangleShape is nullptr !");
	rectangleShape->setOrigin(_origin);
}

void Game::Ground::SetScale(const sf::Vector2f& _scale)
{
	checkLow((rectangleShape != nullptr), "[Ground] => rectangleShape is nullptr !");
	rectangleShape->setScale(_scale);
}

sf::Vector2f Game::Ground::Position() const
{
	check((rectangleShape != nullptr), "[Ground] => rectangleShape is nullptr !", sf::Vector2f(0, 0));
	return rectangleShape->getPosition();
}

sf::Vector2f Game::Ground::Scale() const
{
	check((rectangleShape != nullptr), "[Ground] => rectangleShape is nullptr !", sf::Vector2f(0, 0));
	return rectangleShape->getScale();
}

sf::Vector2f Game::Ground::Origin() const
{
	check((rectangleShape != nullptr), "[Ground] => rectangleShape is nullptr !", sf::Vector2f(0, 0));
	return rectangleShape->getOrigin();
}
sf::FloatRect Game::Ground::GlobalBounds() const
{
	check((rectangleShape != nullptr), "[Ground] => rectangleShape is nullptr !", sf::FloatRect(0,0,0,0));
	return rectangleShape->getGlobalBounds();
}
#pragma endregion override