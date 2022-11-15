#pragma once
#include "pch.h"
#include "FString.h"
#include "Object.h"



	namespace Core
	{
		namespace PrimitiveType
		{
			#pragma warning(disable : 4996)

			class Boolean;

			class FString sealed : public Object
			{
#pragma region f/p 
			private:
				const char* value = "";
				int length = 0;
			public:
				static const FString Empty;
#pragma endregion f/p
#pragma region constructor/destructor
			public:
				O3DLIBRARY_API FString() = default;
				O3DLIBRARY_API FString(const char* _value)
				{
					if (_value == nullptr) _value = "";
					const int _otherLength = strlen(_value);
					const int _newLength = length + _otherLength;
					char* _array = new char(_newLength + 1);
					strcpy(_array, _value);
					strcat(_array, _value);
					value = _array;
					length = _newLength;

				}
				O3DLIBRARY_API FString(const FString& _copy)
				{
					if (_copy.value == nullptr) return;
					const int _length = _copy.length;
					char* _array = new char(_length + 1);
					memcpy(_array, _copy.value, _length + 1);
					value = _array;
					length = _length;
				}
				O3DLIBRARY_API FString(std::string::iterator _begin, std::string::iterator _end)
				{
					for (; _begin != _end; ++_begin)
						Append(*_begin);
				}
#pragma endregion constructor/destructor
#pragma region methods 
			public:
				O3DLIBRARY_API void Append(const FString& _str)
				{
					const int _newLength = length + _str.length;
					char* _array = new char[_newLength + 1];
					strcpy(_array, _str.value);
					strcat(_array, _str.value);
					value = _array;
					length = _newLength;
				}
				O3DLIBRARY_API void Append(const char _value)
				{
					const int _newLength = length + 2;
					char* _array = new char[_newLength];
					strcpy(_array, value);
					_array[length] = _value;
					_array[length + 1] = '\0';
					value = _array;
					length += 1;
				}
				O3DLIBRARY_API FString SubString(const int _begin, const int _end); 
				O3DLIBRARY_API FString SubString(const int _begin);
				O3DLIBRARY_API FString Replace(const char _old, const char _new) const ;
				O3DLIBRARY_API FString Replace(const FString& _old, const FString& _new) const;
				O3DLIBRARY_API FString Trim() const; 
				O3DLIBRARY_API FString ToLower() const; 
				O3DLIBRARY_API FString ToUpper() const; 
				O3DLIBRARY_API int Length() const
				{
					return length;
				}
				O3DLIBRARY_API const char* ToCstr() const
				{
					return value; 
				}
				O3DLIBRARY_API Boolean IsNullOrEmpty(const FString& _str); 
#pragma endregion methods
#pragma region override
			public: 
				O3DLIBRARY_API FString ToString() const override;
#pragma endregion override
#pragma region operator
			public:
				O3DLIBRARY_API operator const char* () const
				{
					return value;
				}
				O3DLIBRARY_API friend std::ostream& operator<<(std::ostream& _os, const FString& _str)
				{
					_os << _str.value;
					return _os; 
				}
				O3DLIBRARY_API Boolean operator==(const FString& _other); 
				O3DLIBRARY_API Boolean operator!=(const FString& _other);
#pragma endregion operator 
			};
		}
}






