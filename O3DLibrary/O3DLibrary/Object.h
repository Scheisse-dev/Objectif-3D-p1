#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <map> 
#include <tuple>
#include "O3DLibrary.h"

// fail count = 9

//namespace Core
//{
//
//
//	namespace PrimitiveType
//	{
//		class FString;
//		class Boolean;
//	}
//	template<typename Var>
//	class O3DLIBRARY_API FieldInfo
//	{
//	private:
//		Core::PrimitiveType::FString name;
//		Var variable;
//	public:
//		FieldInfo(Core::PrimitiveType::FString _name, Var _variable)
//		{
//			name = _name;
//			variable = _variable;
//			std::map< _name, _variable> map; 
//		}
//
//	};
//}

namespace Core
{
	template<typename T>
	struct FileInfo
	{
		std::string _name = "";
		//todo enum 
		T value = nullptr; 

	};

	enum variable
	{
		name,
		Public, 
		Private, 
		Protected, 
		variable

	};

	

	 
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
		
	}
	
	class O3DLIBRARY_API Object
	{
#pragma region f/p
	public:
		template<typename T, typename Name, typename Value>
		static std::tuple<Name&, T&, Value&> Mytuple;
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		Object() = default;
		virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
	public:
		virtual Core::PrimitiveType::Boolean Equals(const Object* _obj) const;
		virtual Core::PrimitiveType::FString ToString() const; 
		template<typename T, typename Name, typename Value>
		static void Register(Name& _name, T& _public, Value& _value);
		template<typename T, typename Name, typename Value>
		static void GetField(std::string _name)
		{
			std::cout << std::get<_name>(Mytuple<Name&,T&, Value&>);

		}


#pragma endregion methods 

		};
		typedef Object* object;
	
}

template<typename T, typename Name, typename Value>
void Core::Object::Register(Name& _name, T& _public, Value& _value)
{
	std::tie(Name& _name)(Mytuple<Name&,T&, Value&>);
} 