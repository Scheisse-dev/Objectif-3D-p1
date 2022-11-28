#include "MethodsInfo.h"
#include "FString.h"

#pragma region constructor 
Core::MethodsInfo::MethodsInfo(Core::PrimitiveType::FString _name, std::vector<Object*> _param)
{
	name = _name;
	param = _param;
}
Core::PrimitiveType::FString Core::MethodsInfo::Name()
{
	return name; 
}
std::vector<Core::Object*> Core::MethodsInfo::Param()
{
	return param; 
}
Core::PrimitiveType::FString Core::MethodsInfo::ToString() const
{
	return name;
}
#pragma endregion constructor
#pragma region methods

#pragma endregion methods
#pragma region overrides

#pragma endregion override


