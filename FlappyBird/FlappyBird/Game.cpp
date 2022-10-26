#include "Game.h"
#include "Utils.h"
#include <iostream>
#include <random>
void Game::DrawBorder()
{

	for (int i = 0; i < SCREEN_WIDTH; i++)
	{
		Utils::SetCursorPosition(i, 0); 
		std::cout << "±";
		Utils::SetCursorPosition(i, SCREEN_HEIGHT); 
		std::cout << "±";
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		Utils::SetCursorPosition(0, i);
		std::cout << "±";
		Utils::SetCursorPosition( SCREEN_WIDTH, i);
		std::cout << "±";
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		Utils::SetCursorPosition(WIN_WIDTH, i);
		std::cout << "±";
	}
	


}

void Game::DrawBird()
{
	
	pipe.PositionPipe();
	Utils::SetCursorPosition(2, h);
	for (int i = 0; i < 2; i++)
	{

		for (int x = 0; x < 6; x++)
			std::cout << bird[i][x];

		std::cout << std::endl;
		Utils::SetCursorPosition(2, h + 1);



	}
	OneUpdate();
}

void Game::OneUpdate()
{
	if (isDeath == false)
	{
		char uc = Utils::CinNoBlock();
		if (uc == SPACE)
		{
			h--;
			Game::EraseBird(h + 3);
			Game::EraseBird(h);
			if (h == 0 || SCREEN_HEIGHT)
			{
				isDeath == true;
			}
		}
		else
		{
			h++;
			Game::EraseBird(h - 2);
			Game::EraseBird(h + 1);
			if (h == 0 || SCREEN_HEIGHT)
			{
				isDeath == true;
			}
		}
	}
	else
	{
		system("CLS");
		std::cout << "GameOver"; 
	}

}

void Game::EraseBird(int _h)
{
	Utils::SetCursorPosition(2, _h);
	std::cout << clear << std::endl;

}


