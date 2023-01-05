#include "Pipe.h"

Pipe::Pipe()
{
	SetSprite();
}

void Pipe::SetSprite()
{
	pipeTexture.loadFromFile(texture);
	pipeSprite.setPosition(300, 400);
	pipeSprite.setTexture(pipeTexture);
	pipeSprite.setScale(0.5f, 0.5f);
	pipe2Sprite.rotate(180);
	pipe2Sprite.setPosition(412, 200);
	pipe2Sprite.setTexture(pipeTexture);
	pipe2Sprite.setScale(0.5f, 0.5f);
}
