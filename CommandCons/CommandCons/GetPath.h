#pragma once
#include "Object.h"

class Path : public Object
{
#pragma region constructor
	Path() = default; 
	Path(const Path& _copy) = default; 
#pragma endregion constructor
#pragma region methods
	void ValidPath();
#pragma endregion methods
};

