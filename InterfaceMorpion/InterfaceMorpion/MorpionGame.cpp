#include "MorpionGame.h"
#include <iostream>


void MorpionGame::Display()
{
	std::cout << "----++---++----" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < 4; x++)
		{
			std::cout << "| " << tab[i];
		}
		std::cout << std::endl << "----++---++----" << std::endl;
	}
}

void MorpionGame::Game()
{
	command = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 }; 
	
}



