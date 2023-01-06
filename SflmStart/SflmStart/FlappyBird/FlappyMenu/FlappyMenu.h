#pragma once
#include <SFML/Graphics.hpp>
class FlappyMenu
{
#pragma region f/p
	public:
	sf::Texture retryTexture = sf::Texture();
	sf::Texture exitTexture = sf::Texture();
	sf::Texture startTexture = sf::Texture();
	sf::Texture titleTexture = sf::Texture();
	sf::Sprite startSprite = sf::Sprite();
	sf::Sprite titleSprite = sf::Sprite();
	sf::Sprite exitSprite = sf::Sprite();
	sf::Sprite retrySprite = sf::Sprite();
	sf::Color color = sf::Color(0, 0, 0);
	sf::Text text = sf::Text();;
	sf::Font font;


#pragma endregion f/p
#pragma region constructor
public:
	FlappyMenu();
#pragma endregion constructor
#pragma region methods
public:
	void SetGameOverSprite();
	void SetGameStart();
	void SetCollision();
#pragma endregion mehods
};

