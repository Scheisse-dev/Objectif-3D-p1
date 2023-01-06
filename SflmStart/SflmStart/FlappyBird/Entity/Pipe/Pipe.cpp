#include "Pipe.h"

Pipe::Pipe()
{
	SetSprite();
}

void Pipe::SetSprite()
{
	pipeTexture.loadFromFile(texture);


	pipeSprite.setTexture(pipeTexture);
	pipe2Sprite.setTexture(pipeTexture);
	pipeSprite.setScale(0.5f, 0.5f);
	pipe2Sprite.setScale(0.5f, 0.5f);
	pipeSprite.setPosition(300, 400);
	pipe2Sprite.setPosition(412, 100);
	pipe2Sprite.rotate(180);


	pipe3Sprite.setTexture(pipeTexture);
	pipe4Sprite.setTexture(pipeTexture);
	pipe3Sprite.setScale(0.5f, 0.5f);
	pipe4Sprite.setScale(0.5f, 0.5f);
	pipe3Sprite.setPosition(900, 550);
	pipe4Sprite.setPosition(1012, 250);
	pipe4Sprite.rotate(180);
}
