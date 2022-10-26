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
	PositionPipe();
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
	
	char uc = Utils::CinNoBlock();
	if (uc == SPACE) 
	{
		h--;
		Game::EraseBird(h + 3);
		Game::EraseBird(h);

	}
	else
	{
		h++;
		Game::EraseBird(h - 2);
		Game::EraseBird(h + 1);
	} 
	
}

void Game::EraseBird(int _h)
{
	Utils::SetCursorPosition(2, _h);
	std::cout << clear << std::endl;

}

void Game::ErasePipe()
{
	int _tmp = wallPos;

		for (int x = 1; x < SCREEN_HEIGHT; x++) //TODO 
		{
			Utils::SetCursorPosition(_tmp + 4, x);
			std::cout << ' ';
		}
		_tmp++;
}

int Game::Random(int _min, int _max)
{
	std::random_device _rd = std::random_device();
	std::mt19937 _gen(_rd());
	const std::uniform_int_distribution<> _distr = std::uniform_int_distribution<>(_min, _max);
	const int _result = _distr(_gen);
	return _result; 

}
void Game::GeneratePipe(int _index)
{
	
	int _tmp = wallPos;
	

		for (int g = 0; g < 3; g++)
		{

			for (int x = 1; x < SCREEN_HEIGHT; x++)
			{
				Utils::SetCursorPosition(_tmp, x);
				if (wallPos > 1)
					std::cout << '*';
			}
			_tmp++;
		}
		_tmp = wallPos;
		if (wallPos+3 > 1)
		{
			for (int p = 0; p < 3; p++)
			{
				for (int i = 0; i < BETWEEN; i++)
				{
					Utils::SetCursorPosition(_tmp, _index);
					std::cout << ' ';
					_index++;
				}
				_index -= BETWEEN;
				_tmp++;

			}
			wallPos--;
		}
}

void Game::PositionPipe() //TODO 
{
	
		GeneratePipe(_rand); 
		ErasePipe(); 
	
}
