#pragma once
#include "Object.h"
class DateTime : public Object
{
#pragma region f/p
private:
	int day = 0;
	int month = 0;
	int years = 0;
	int hour = 0;
	int minute = 0;
	int second = 0;
public:
	static DateTime Now;
#pragma endregion f/p
#pragma region constructor
public:
	DateTime() = default;
	DateTime(const int _day, const int _month, const int _years, const int _hour, const int _minute, const int _second);
	DateTime(const DateTime& _copy);
#pragma endregion constructor
#pragma region methods
private:
	static DateTime NowInternal();
public:
	static DateTime Parse(const std::string& _str);
#pragma endregion methods
#pragma region override
public:
	std::string ToString() const override;
#pragma endregion override
#pragma region operator
public:
#pragma endregion operator
};

