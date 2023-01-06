#include "Bird.h"

#pragma region constructor
Bird::Bird()
{
	SetSprite();
}
#pragma endregion constructor
#pragma region methods
void Bird::SetSprite()
{
	texture.loadFromFile(texturePath);
	birdSprite.setPosition(0, 300);
	birdSprite.setTexture(texture);
	birdSprite.setScale(0.1f, 0.1f);
}
#pragma endregion methods