#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <map> 
#include "O3DLibrary.h"

// fail count = 8

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
	//template<typename T>
	//struct FileInfo
	//{
	//	PrimitiveType::FString name;
	//	T value;

	//};

	 
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
	}
	
	class O3DLIBRARY_API Object
	{

#pragma region constructor/destructor
	public:
		Object() = default;
		virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
	public:
		virtual Core::PrimitiveType::Boolean Equals(const Object* _obj) const;
		virtual Core::PrimitiveType::FString ToString() const;

#pragma endregion methods 

		};
		typedef Object* object;

	
}

