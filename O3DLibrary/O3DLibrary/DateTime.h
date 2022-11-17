#pragma once
#include "Object.h"
#include "EDayOfWeek.h"

namespace Core
{

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
		EDayOfWeek dayOfWeek = EDayOfWeek::Sunday;
#pragma endregion f/P
#pragma region constructor	
	public: 
		O3DLIBRARY_API DateTime(const int _day, const int _month, const int _years, const int _hour, const int _minute, const int _second);
		O3DLIBRARY_API DateTime(const int _day, const int _month, const int _years, const int _hour, const int _minute);
		O3DLIBRARY_API DateTime(const int _day, const int _month, const int _years, const int _hour);
		O3DLIBRARY_API DateTime(const int _day, const int _month, const int _years);
		O3DLIBRARY_API DateTime(const DateTime& _copy);
#pragma endregion constructor
#pragma region methods
	private: 
		O3DLIBRARY_API int CalculateDayOfWeek() const; 
	public:
		O3DLIBRARY_API EDayOfWeek DayOfWeek() const; 
		O3DLIBRARY_API static DateTime Now(); 
		O3DLIBRARY_API void AddDay(const int _value);
		O3DLIBRARY_API void AddMonth(const int _value);
		O3DLIBRARY_API void AddYears(const int _value);
		O3DLIBRARY_API void AddHour(const int _value);
		O3DLIBRARY_API void AddMinute(const int _value);
		O3DLIBRARY_API void AddSecond(const int _value);
		O3DLIBRARY_API PrimitiveType::FString ToStringFormat(const PrimitiveType::FString& _format) const;
		O3DLIBRARY_API PrimitiveType::Boolean Equals(const DateTime& _obj) const;
		
#pragma endregion methods
#pragma region override
	public:
		O3DLIBRARY_API PrimitiveType::FString ToString() const override;
		O3DLIBRARY_API PrimitiveType::Boolean Equals(const Object* _obj) const override;
#pragma endregion override

	};
}
