#include "FlappyMenu.h"
#include <iostream>
FlappyMenu::FlappyMenu()
{
	SetGameOverSprite();
	SetGameStart();
	
}

void FlappyMenu::SetGameOverSprite()
{
	if (!exitTexture.loadFromFile("../Sprites/Exit.png")) return;
	if (!retryTexture.loadFromFile("../Sprites/restart.png")) return;

	exitSprite.setTexture(exitTexture);
	exitSprite.setScale(0.03f, 0.03f);
	exitSprite.setPosition(300, 350);
	retrySprite.setTexture(retryTexture);
	retrySprite.setScale(0.22f, 0.22f);
	retrySprite.setPosition(380, 350);
	
	
	font = sf::Font();
	if (!font.loadFromFile("../Fonts/game_over.ttf")) return;

	text.setFont(font);
	text.setFillColor(color);
	text.setString("GameOver");
	text.setCharacterSize(70);
	text.setPosition(300, 250);



}

void FlappyMenu::SetGameStart()
{
	if (!startTexture.loadFromFile("../Sprites/start.png")) return;
	if (!titleTexture.loadFromFile("../Sprites/title.png")) return;


	titleSprite.setTexture(titleTexture);
	titleSprite.setScale(0.5, 0.5f);
	titleSprite.setPosition(250, 150);

	startSprite.setTexture(startTexture);
	startSprite.setScale(0.3f, 0.3f);
	startSprite.setPosition(350, 250);
}


