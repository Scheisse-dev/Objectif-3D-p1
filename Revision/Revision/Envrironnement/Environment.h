#pragma once
#include "..\Object\Object.h"

class Environment : public Object
{
	static std::string CurrentDirectory();
};