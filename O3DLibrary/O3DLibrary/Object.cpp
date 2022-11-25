#include "Object.h"
#include "FString.h"
#include "Boolean.h"
#include <iostream>

#pragma region methods
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::Object::Equals(const Object* _obj) const
{
	return this == _obj;
}

O3DLIBRARY_API Core::PrimitiveType::FString Core::Object::ToString() const
{
	return "";
}
#pragma endregion methods

