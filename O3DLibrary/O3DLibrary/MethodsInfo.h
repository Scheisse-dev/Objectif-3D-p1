#pragma once
#include "Object.h"
#include <vector>

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
		class Interger;
	}
	class MethodsInfo : public Object
	{
#pragma region f/p 
	private: 
		PrimitiveType::FString name = ""; 
		std::vector<Object*> param = std::vector<Object*>();
#pragma endregion f/p
#pragma region constructor 
	public:
		MethodsInfo() = default; 
		MethodsInfo(PrimitiveType::FString _name, std::vector<Object*> _param);
#pragma endregion constructor
#pragma region methods
	protected: 
		
	public:
		PrimitiveType::FString Name();
		std::vector<Object*> Param();
#pragma endregion methods
#pragma region overrides
	public:
		PrimitiveType::FString ToString() const;
#pragma endregion override
	};

}