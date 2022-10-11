#pragma once
#include "invent.h"

class Player
{
private :
	int life = 1; 
public: 
	int Recover(); 
};
/*
Player::Recover() 
{
	if (life < 100 && invent::UsePotion())
		life = life + 10; 
	if (life > 100)
		life = 100;
	else
		life = life; 
}
*/