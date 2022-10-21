#include "DateTime.h"
#include "StringUtils.h"
#include <format>
#include <ctime>

#pragma warning(disable: 4996)

#pragma region f/p
DateTime DateTime::Now = DateTime::NowInternal();
#pragma endregion f/p

#pragma region constructor
DateTime::DateTime(const int _day, const int _month, const int _years, const int _hour, const int _minute, const int _second)
{
	day = _day;
	month = _month;
	years = _years;
	hour = _hour;
	minute = _minute;
	second = _second;
}

DateTime::DateTime(const DateTime& _copy)
{
	day = _copy.day;
	month = _copy.month;
	years = _copy.years;
	hour = _copy.hour;
	minute = _copy.minute;
	second = _copy.second;
}

#pragma endregion constructor

#pragma region methods
DateTime DateTime::NowInternal()
{
	const time_t _now = time(nullptr);
	const std::tm _tm = *localtime(&_now);
	return DateTime(_tm.tm_mday, _tm.tm_mon + 1, _tm.tm_year + 1900, _tm.tm_hour, _tm.tm_min, _tm.tm_sec);
}

DateTime DateTime::Parse(const std::string& _str)
{
	std::vector<std::string> _splitedTime = StringUtils::Split(_str, ' ');
	std::vector<std::string> _ymd = StringUtils::Split(_splitedTime[0], '/');
	std::vector<std::string> _hms = StringUtils::Split(_splitedTime[1], ':');

	const int _day = std::stoi(_ymd[0]);
	const int _month = std::stoi(_ymd[1]);
	const int _years = std::stoi(_ymd[2]);

	const int _hour = std::stoi(_hms[0]);
	const int _minute = std::stoi(_hms[1]);
	const int _second = std::stoi(_hms[2]);

	return DateTime(_day, _month, _years, _hour, _minute, _second);
}
#pragma endregion methods

#pragma region override
std::string DateTime::ToString() const
{
	return std::format("{:02}/{:02}/{:02} {:02}:{:02}:{:02}", day, month, years, hour, minute, second);
}
#pragma endregion override