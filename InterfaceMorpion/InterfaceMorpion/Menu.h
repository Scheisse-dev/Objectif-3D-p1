#pragma once
#include "BattleMenu.h"
#include "StartMenu.h"
#include "MorpionGame.h"

class Menu
{
#pragma region f/p
private : 
	int playerChoice = 0;
	StartMenu Smenu = StartMenu();
	BattleMenu Bmenu = BattleMenu();
	MorpionGame Morpion = MorpionGame(); 
#pragma endregion f/p 
#pragma region constructor
public:
	Menu() = default;

#pragma endregion constructor
#pragma region Methods
public : 
	void Navigation();
	void StartBattleM(); 
#pragma endregion Methods
};

