#pragma once
#include "Utils.h"
#include "Object.h"

class Echo : public Object
{
	Echo() = default;
	Echo(const Echo& _copy) = default; 

	bool Jecho(); 
	std::string Cecho(); 
};

