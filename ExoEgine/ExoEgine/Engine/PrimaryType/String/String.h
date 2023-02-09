#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Boolean;
	UCLASS()
	class String : public ValueType
	{
		DECLARE_CLASS_INFO(String, ValueType) 
#pragma region f/p
	private:
		const char* value = nullptr;
		size_t length = 0;
#pragma endregion f/p
#pragma region constructor
	public:
		String() = default;
		String(const char* _value);
#pragma endregion constructor
#pragma region methods
	public:
		Boolean StartWith(char _c) const; 
		Boolean EndWith(char _c) const;
		Boolean StartWith(const String& _str) const;
		Boolean EnWith(const String& _str) const; 
		Boolean EqualsIgnoreCase(const String& _str) const; 
		Boolean Contains(const String& _str) const; 
		static Boolean IsNullOrEmpty(const String& _str);


		String ToLower() const;
		String ToUpper() const;
		String SubString(size_t _begin) const;
		String SubString(size_t _begin, size_t _end) const;
		String Replace(const String& _old, const String& _new) const; 
		String Replace(char _old, char _new); 
		String Trim() const;
		size_t FindFirstOf(char _c) const; // TODO replace int with Integer class
		size_t FindLastOf(char _c) const; //TODO replace int with integer class
		size_t Lenght() const; //TODO replace int with Integerclass
		void Append(const char* _str);
		void Append(char _char);
		void Append(const String& _str);
		const char* ToCstr() const;

#pragma endregion methods
#pragma region override
	public:
		String ToString() const override;
		void SerializeField(std::ostream& _os, const PrimaryType::String& _fieldName, int _index) override;
		void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName) override;
#pragma endregion override
#pragma region operator
	public:
		String& operator+=(const char* _str);
		String& operator+=(const String& _str);
		String& operator+=(char _c);
		operator const char* ();
		operator const char* () const;
		Boolean operator==(const String& _str) const;
		Boolean operator!=(const String& _str) const;
		Boolean operator==(const char* _str) const;
		Boolean operator!=(const char* _str) const;
		Object& operator=(const Object* _other) override; 
		String& operator=(const String& _other); 
#pragma endregion operator
	};

}
