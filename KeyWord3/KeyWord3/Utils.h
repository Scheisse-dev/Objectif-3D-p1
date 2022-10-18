#pragma once
#include <string>
#include <iostream>
#include "ScriptingSymbol.h"

class Utils
{
public: 
	static void Log(const std::string& _msg)
	{

#ifdef DEBUG
		std::cout << "[Debug] => " << _msg << std::endl;
/*
#elif defined(RELEASE)
		std::cout << "[Release] => " << _msg << std::endl;
#else DEBUG
		std::cout << "[Master] => " << _msg << std::endl;*/
#endif

	}
};

