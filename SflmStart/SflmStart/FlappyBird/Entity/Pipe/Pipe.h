#pragma once
#include "../Entity.h"

class Pipe : public Entity
{
#pragma region f/p
public:
	//pipe pos difference -> 112
//pipe pos difference | -
	sf::Texture pipeTexture;
	sf::Sprite pipeSprite;
	sf::Sprite pipe2Sprite;
	float speed = 0.1f;
	float height = 1.f;
	float width = 1.f;
	const char* texture = "../Sprites/Pipe.png";
#pragma endregion f/p 
#pragma region constructor
public:
	Pipe();
#pragma endregion constructor
#pragma region methods
public:
	virtual void SetSprite() override;
};
#pragma endregion methods




