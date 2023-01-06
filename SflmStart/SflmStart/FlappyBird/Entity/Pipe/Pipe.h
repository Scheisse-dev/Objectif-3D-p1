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
	sf::Sprite pipe3Sprite;
	sf::Sprite pipe4Sprite;
	float height = 1.f;
	float width = 1.f;
	const char* texture = "../Sprites/Pipe.png";
#pragma endregion f/p 
#pragma region constructor
public:
	Pipe();
	//~Pipe(); 
#pragma endregion constructor
#pragma region methods
public:
	virtual void SetSprite() override;
};
#pragma endregion methods




