#pragma once
#include "../Entity.h"

class Bird : public Entity
{
#pragma region f/p
	public:
	sf::Texture texture;
	sf::Sprite birdSprite;
	bool isOffGame = false;
	const char* texturePath = "../Sprites/FlappyBird.png";
#pragma endregion f/p 
#pragma region constructor
public:
	Bird();
	//~Bird() override = default;
#pragma endregion constructor
#pragma region methods
public:
	void SetSprite() override;
#pragma endregion methods
};

