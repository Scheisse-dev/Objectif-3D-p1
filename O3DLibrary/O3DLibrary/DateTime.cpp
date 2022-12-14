#include "DateTime.h"
#include "FString.h"
#include "Boolean.h"
#include <ctime>


#pragma region constructor
Core::DateTime::DateTime(const SYSTEMTIME& _time)
{
	day = _time.wDay;
	month = _time.wMonth;
	years = _time.wYear;
	hour = _time.wHour;
	minute = _time.wMinute;
	second = _time.wSecond;
	dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}
Core::DateTime::DateTime(const int _day, const int _month, const int _years, const int _hour, const int _minute, const int _second)
{
	day = _day;
	month = _month;
	years = _years;
	hour = _hour;
	minute = _minute; 
	second = _second;
	dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}

Core::DateTime::DateTime(const int _day, const int _month, const int _years, const int _hour, const int _minute)
	:DateTime(_day, _month, _years, _hour, _minute , 0) {}

Core::DateTime::DateTime(const int _day, const int _month, const int _years, const int _hour)
	:DateTime(_day, _month, _years, _hour, 0, 0) {}

Core::DateTime::DateTime(const int _day, const int _month, const int _years)
	:DateTime(_day, _month, _years, 0, 0, 0) {}

Core::DateTime::DateTime(const DateTime& _copy)
{
	day = _copy.day;
	month = _copy.month;
	years = _copy.years;
	hour = _copy.hour;
	minute = _copy.minute;
	second = _copy.second;
	dayOfWeek = _copy.dayOfWeek;
}

#pragma endregion constructor

#pragma region methods

O3DLIBRARY_API int Core::DateTime::CalculateDayOfWeek() const
{
	const int _m = month; 
	int _y = years;
	const int _d = day;
	_y -= _m < 3;
	static int _t[] = { 0,3,2,5,0,3,
						5,1,4,6,2,4 }; 
	return (_y + _y / 4 - _y / 100 + _y/ 400 + _t[_m - 1] + _d) % 7;

	
}

O3DLIBRARY_API Core::EDayOfWeek Core::DateTime::DayOfWeek() const
{
	return dayOfWeek; 
}

O3DLIBRARY_API Core::DateTime Core::DateTime::Now()
{
	const time_t _now = time(nullptr);
	std::tm _tm = std::tm();
	localtime_s(&_tm, &_now);
	return DateTime(_tm.tm_mday, _tm.tm_mon + 1, _tm.tm_year + 1900, _tm.tm_hour, _tm.tm_min, _tm.tm_sec); 

}

O3DLIBRARY_API void Core::DateTime::AddDay(const int _value)
{
	day += _value;
	while (day > 30)
	{
		day -= 30;
		AddMonth(1); 
		dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
	}
}
O3DLIBRARY_API void Core::DateTime::AddMonth(const int _value)
{
	month += _value;
	while (month > 12)
	{
		month -= 12;
		AddYears(1);
	}
	dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}
O3DLIBRARY_API void Core::DateTime::AddYears(const int _value)
{
	years += _value;
	dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();

}
O3DLIBRARY_API void Core::DateTime::AddHour(const int _value)
{
	hour += _value;
	while (hour > 24)
	{
		hour -= 24;
		AddDay(1);
	}
}
O3DLIBRARY_API void Core::DateTime::AddMinute(const int _value)
{
	minute += _value;
	while (minute > 60)
	{
		minute -= 60;
		AddHour(1);
	}
}
O3DLIBRARY_API void Core::DateTime::AddSecond(const int _value)
{
	second += _value;
	while (second > 60)
	{
		second -= 60;
		AddMinute(1);
	}
}

O3DLIBRARY_API Core::PrimitiveType::FString Core::DateTime::ToStringFormat(const Core::PrimitiveType::FString& _format) const
{
	if (PrimitiveType::FString::IsNullOrEmpty(_format))return "format error"; 
	PrimitiveType::FString _result = _format;

	const PrimitiveType::FString _monthCstr = std::to_string(month).c_str();
	const PrimitiveType::FString _dayCstr = std::to_string(day).c_str();
	const PrimitiveType::FString _hourCstr = std::to_string(hour).c_str();
	const PrimitiveType::FString _minuteCstr = std::to_string(minute).c_str();
	const PrimitiveType::FString _secondCstr = std::to_string(second).c_str();

	_result = _result.Replace("Y", std::to_string(years).c_str());
	_result = _result.Replace("M", month < 10 ? PrimitiveType::FString("O") + _monthCstr : _monthCstr);
	_result = _result.Replace("D", day < 10 ? PrimitiveType::FString("O") + _dayCstr : _dayCstr);
	_result = _result.Replace("h", hour < 10 ? PrimitiveType::FString("O") + _hourCstr : _hourCstr);
	_result = _result.Replace("m", minute < 10 ? PrimitiveType::FString("O") + _minuteCstr : _minuteCstr);
	_result = _result.Replace("s", second < 10 ? PrimitiveType::FString("O") + _secondCstr : _secondCstr);
	return _result; 

}
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::DateTime::Equals(const DateTime& _obj) const
{
	return day == _obj.day &&
		month == _obj.month &&
		years == _obj.years &&
		hour == _obj.hour &&
		minute == _obj.minute &&
		second == _obj.second;
}

#pragma endregion methods

#pragma region override

O3DLIBRARY_API Core::PrimitiveType::FString Core::DateTime::ToString() const
{
	return ToStringFormat("h:m:s D-M-Y"); 
}

O3DLIBRARY_API Core::PrimitiveType::Boolean Core::DateTime::Equals(const Object* _obj) const
{
	const DateTime* _other = dynamic_cast<const DateTime*>(_obj);
	if (_other == nullptr) return false;
	return Equals(*_other); 
}
#pragma endregion override