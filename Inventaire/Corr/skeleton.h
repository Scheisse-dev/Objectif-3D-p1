#pragma once
#include "Mob.h"
#include "Vector2.h"
// https://youtu.be/-1dSY6ZuXEY 

class Skeleton : public Mob
{
	Skeleton() = default; 
	Skeleton(const std::string& _name, Vector2* _position = new Vector2(0, 0), const float _maxLife = 50.0f, const float _maxMana = 10.0f); 
	// tentative d'héritage mais je suis une merde... je dois attribuer des valeurs fixe sur cette ligne mais je sais pas comment... je crois que c'est bon 
	//
};

