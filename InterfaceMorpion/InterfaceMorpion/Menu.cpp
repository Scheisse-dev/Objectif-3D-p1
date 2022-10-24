#include "Menu.h"
#include <iostream>

#pragma region CommentZone
/*
* rendre evolutif
*/
#pragma endregion CommentZone
#pragma region methods
void Menu::Navigation()
{
	
	
	Smenu.Menu("Start");
	while (playerChoice != 1)
	{
		std::cin >> playerChoice;
	}
	Menu::StartBattleM();
	playerChoice = 0;
}

void Menu::StartBattleM()
{
	system("CLS");
	Bmenu.Menu("Morpion");
	while (playerChoice != 1 || 2)
	{
		std::cin >> playerChoice;
		
	}
	if (playerChoice == 1) // remplacer la valeur 1 par un vecteur de la taille de game ?
	{
		// call game
	}
	else
		Smenu.Menu("Start");

	playerChoice = 0;
}
#pragma endregion methods