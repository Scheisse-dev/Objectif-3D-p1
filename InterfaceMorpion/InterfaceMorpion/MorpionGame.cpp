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
	while (win == false)
	{
		int playerChoice = 0;
		while (playerChoice != 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9)
			std::cin >> playerChoice;
		if (playerChoice == 1)
		{
			if (player)
				tab[0] = " X ";
			else
				tab[0] = " O ";
			player = !player;
		}
		if (playerChoice == 2)
		{
			if (player)
				tab[1] = " X ";
			else
				tab[1] = " O ";
			player = !player;
		}
		if (playerChoice == 3)
		{
			if (player)
				tab[2] = " X ";
			else
				tab[2] = " O ";
			player = !player;
		}
		if (playerChoice == 4)
		{
			if (player)
				tab[3] = " X ";
			else
				tab[3] = " O ";
			player = !player;
		}
		if (playerChoice == 5)
		{
			if (player)
				tab[4] = " X ";
			else
				tab[4] = " O ";
			player = !player;
		}
		if (playerChoice == 6)
		{
			if (player)
				tab[5] = " X ";
			else
				tab[5] = " O ";
			player = !player;
		}
		if (playerChoice == 7)
		{
			if (player)
				tab[6] = " X ";
			else
				tab[6] = " O ";
			player = !player;
		}
		if (playerChoice == 8)
		{
			if (player)
				tab[7] = " X ";
			else
				tab[7] = " O ";
			player = !player;
		}
		if (playerChoice == 9)
		{
			if (player)
				tab[8] = " X ";
			else
				tab[8] = " O ";
			player = !player;
		}
		Display();
	}

}

