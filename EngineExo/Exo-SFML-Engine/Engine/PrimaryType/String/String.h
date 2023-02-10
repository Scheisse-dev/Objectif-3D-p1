#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Boolean;
    UCLASS()
	class String : public ValueType
	{
		DECLARE_CLASS_INFO(String, ValueType)
#pragma region var
	private:
		const char* value = nullptr;
        size_t length = 0;
#pragma endregion
#pragma region const/dest
	public:
		String() {}
		String(const char* _value);
#pragma endregion
#pragma region methods
	public:
		Boolean StartWith(char _c) const;
		Boolean EndWith(char _c) const;
		Boolean StartWith(const String& _str) const;
		Boolean EndWith(const String& _str) const;
		Boolean EqualsIgnoreCase(const String& _str) const;
		Boolean Contains(const String& _str) const;
		UFUNCTION() static Boolean IsNullOrEmpty(const String& _str);
REGISTER_METHOD(IsNullOrEmpty, &String::IsNullOrEmpty, (std::vector{new Engine::Reflection::ParameterInfo("_str", 0)}), BindingFlags::Public)
		const char* ToCstr() const;
		String SubString(size_t _begin) const;
		String SubString(size_t _begin, size_t _end) const;
		String Replace(const String& _old, const String& _new) const;
		String Replace(char _old, char _new);
		String Trim() const;
		String ToLower() const;
		String ToUpper() const;
		size_t FindFirstOf(char _c) const; //TODO int -> Integer
		size_t FindLastOf(char _c) const; //TODO int -> Integer
		size_t Length() const; //TODO int -> Integer
		void Append(const char* _str);
		void Append(char _c);
		void Append(const String& _str);
#pragma endregion
#pragma region override
	public:
		String ToString() const override;
        void SerializeField(std::ostream& _os, const PrimaryType::String& _fieldName, int _index) override;
        void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName) override;
#pragma endregion
#pragma region operator
	public:
		operator const char* ();
		operator const char* () const;
        Object& operator=(const Object* _other) override;
		String& operator=(const String& _other);
		Boolean operator==(const char* _other) const;
		Boolean operator!=(const char* _other) const;
		Boolean operator==(const String& _other) const;
		Boolean operator!=(const String& _other) const;
		String& operator+=(const char* _other);
		String& operator+=(char _c);
		String& operator+=(const String& _other);
#pragma endregion
	};
}


namespace Engine::PrimaryType
{
    class String;
    REGISTER_CLASS(String)
}
