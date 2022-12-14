#pragma once
#include "FString.h"
#include "Object.h"
#include <vector> 



namespace Core
{
#pragma warning(disable : 4996)


	class Object;

	namespace PrimitiveType
	{
		class Boolean;
		class Integer;

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
				char* _char = new char[_newLength + 1];
				strcpy(_char, value);
				strcat(_char, _value);
				value = _char;
				length = _newLength;

			}
			O3DLIBRARY_API FString(const FString& _copy)
			{
				if (_copy.value == nullptr) return;
				const size_t _length = _copy.length;
				char* _new = new char[_length + 1];
				memcpy(_new, _copy.value, _length + 1);
				value = _new;
				length = _copy.length;
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
				strcpy(_array, value);
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
			O3DLIBRARY_API static FString Convert(const std::wstring& _wstring); 
			O3DLIBRARY_API FString SubString(const int _begin, const int _end) const ;
			O3DLIBRARY_API FString SubString(const int _begin) const ;
			O3DLIBRARY_API FString Replace(const char _old, const char _new) const;
			O3DLIBRARY_API FString Replace(const FString& _old, const FString& _new) const;
			O3DLIBRARY_API FString Trim() const;
			O3DLIBRARY_API FString ToLower() const;
			O3DLIBRARY_API FString ToUpper() const;
			O3DLIBRARY_API Integer Length() const;
			O3DLIBRARY_API Boolean StartWith(const char _c) const;
			O3DLIBRARY_API Boolean StartWith(const FString& _str) const;
			O3DLIBRARY_API Boolean EndWith(const char _c) const;
			O3DLIBRARY_API Boolean EndWith(const FString& _str) const;
			O3DLIBRARY_API Boolean Contains(const FString& _str) const;
			O3DLIBRARY_API Integer LastIndexOf(const char _c) const;
			O3DLIBRARY_API Integer FirstIndexOf(const char _c) const;
			O3DLIBRARY_API Integer Find(const FString& _str) const;
			O3DLIBRARY_API std::wstring ToWString() const;
			O3DLIBRARY_API const char* ToCstr() const
			{
				return value;
			}
			O3DLIBRARY_API static Boolean IsNullOrEmpty(const FString& _str);
			O3DLIBRARY_API Boolean Equals(const FString& _other) const;
			template<typename... Args>
			O3DLIBRARY_API static FString Format(const FString& _str, Args... _args);
#pragma endregion methods
#pragma region override
		public:
			O3DLIBRARY_API FString ToString() const override;
			O3DLIBRARY_API Boolean Equals(const Object* _obj) const override;
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
			O3DLIBRARY_API Boolean operator==(const FString& _other) const;
			O3DLIBRARY_API Boolean operator!=(const FString& _other)const;
			O3DLIBRARY_API FString operator+(const FString& _other)const;
			O3DLIBRARY_API FString& operator+=(const FString& _other);
			O3DLIBRARY_API char operator[](const int _index);
#pragma endregion operator 
		};

#pragma region methods
		//{} {} {}
		template<typename... Args>
		inline FString FString::Format(const FString& _str, Args ..._args)
		{
			FString _result = "";
			std::vector<object> _arguments = std::vector<object>();
			(_arguments.push_back(&_args), ...);
			int _index = 0;
			for (int i = 0; i < _str.length; i++)
			{
				if (_str[i] == '{' && _str[i+1] == '}')
				{
					_result.Append(_arguments[_index]->ToString());
					_index++, i++;
				}
				else _result.Append(_str[i]);
			}


			return _result;
		}
	}

}



