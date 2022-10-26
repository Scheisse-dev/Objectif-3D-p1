#include "Pipe.h"
#include "Utils.h"
#include <iostream>
#include <random>

void Pipe::ErasePipe()
{
	int _tmp = wallPos;

	for (int x = 1; x < SCREEN_HEIGHT; x++) //TODO 
	{
		Utils::SetCursorPosition(_tmp + 4, x);
		std::cout << ' ';
	}
	_tmp++;
}

int Pipe::Random(int _min, int _max)
{
	std::random_device _rd = std::random_device();
	std::mt19937 _gen(_rd());
	const std::uniform_int_distribution<> _distr = std::uniform_int_distribution<>(_min, _max);
	const int _result = _distr(_gen);
	return _result;

}
void Pipe::GeneratePipe(int _index)
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
	if (wallPos + 3 > 1)
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

void Pipe::PositionPipe() //TODO 
{

	GeneratePipe(_rand);
	ErasePipe();

}