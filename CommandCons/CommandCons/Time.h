#pragma once
#include <format>
#include "Object.h"

class Time : public Object
{
public: 
	Time() = default;
	Time(Time& _copy) = default;

#pragma region methods
public:
	 void NowInternal();
#pragma endregion methods

};

