#include <iostream>
#include "Menu.h"
#include "MorpionGame.h"
#pragma region CommentZone
/*
* Utils pour cout ? 
*/
#pragma endregion CommentZone
int main()
{
	Menu menu = Menu(); 
	MorpionGame game = MorpionGame(); 
	//menu.Navigation(); 
	game.Display(); 

}

