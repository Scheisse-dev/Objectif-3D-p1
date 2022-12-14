#include "TimeZone.h"



#pragma region constructor
Core::TimeZone::TimeZone(const ETimeZoneName& _timeZone)
{
	timeZone = _timeZone; 
	Init();
}

Core::TimeZone::TimeZone(const TimeZone& _copy)
{
	timeZone = _copy.timeZone;
	result = _copy.result;
	time = _copy.time;
	timeZoneName = _copy.timeZoneName;

}
#pragma endregion constructor
#pragma region methods
void Core::TimeZone::Init()
{
	DYNAMIC_TIME_ZONE_INFORMATION _timeZoneInformation = DYNAMIC_TIME_ZONE_INFORMATION();
	memset(&_timeZoneInformation, 0, sizeof(_timeZoneInformation));
	result = EnumDynamicTimeZoneInformation((int)timeZone, &_timeZoneInformation);
	if (result != ERROR_SUCCESS) return; 
	SYSTEMTIME _systemTime = SYSTEMTIME(); 
	SYSTEMTIME _time = SYSTEMTIME();
	GetSystemTime(&_systemTime);
	SystemTimeToTzSpecificLocalTimeEx(&_timeZoneInformation, &_systemTime, &_time);
	timeZoneName = PrimitiveType::FString::Convert(_timeZoneInformation.TimeZoneKeyName);
	time = DateTime(_time); 

}
Core::DateTime Core::TimeZone::Time() const
{
	return time;
}

Core::PrimitiveType::FString Core::TimeZone::ToString() const
{
	return PrimitiveType::FString::Format("TimeZone: {} => {}", timeZoneName, time); 
}

#pragma endregion methods