#include "BattleMenu.h"
#include <iostream> 
#include <vector>

void BattleMenu::Menu(std::string _name)
{
		std::cout << _name << std::endl << std::endl;
		std::vector<std::string> game = { "Player vs Player", "Player vs IA" };
		for (int i = 0; i < game.size(); i++)
		{

			std::cout << i + 1 << "-" << game[i] << std::endl;
		}

}
