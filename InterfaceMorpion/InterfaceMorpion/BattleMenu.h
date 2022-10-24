#pragma once
#include "Abstract.h"

class BattleMenu : public Abstract
{
public:
	virtual void Menu(std::string _name) override; 
};

