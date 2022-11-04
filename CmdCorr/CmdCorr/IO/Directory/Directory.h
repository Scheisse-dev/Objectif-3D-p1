#pragma once
#include "../../Object/Object.h"


class Directory : public Object
{
#pragma region methods 
public: 
	static bool DirectoryExist(const std::string& _path);
#pragma endregion methods
};

