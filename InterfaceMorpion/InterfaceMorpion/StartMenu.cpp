#include "StartMenu.h"
#include <iostream>
#include <vector>

void StartMenu::Menu(std::string _name)
{
	std::cout << _name << std::endl << std::endl;
	std::vector<std::string> game = { "Morpion", "other Game",  "Return" };
	for (int i = 0; i < game.size() ; i++)
	{
	
		std::cout << i + 1 << "-" << game[i] << std::endl;
	}
}
