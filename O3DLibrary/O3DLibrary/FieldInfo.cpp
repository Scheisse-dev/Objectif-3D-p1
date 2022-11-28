#include "FieldInfo.h"
#include "Boolean.h"


#pragma region constructor
Core::FieldInfo::FieldInfo(const PrimitiveType::FString& _name, object _reflectedObject, int _mask)
{
	name = _name;
	reflectedObject = _reflectedObject;
	flags = (BindingFlags)_mask; 
}
#pragma endregion constructor

#pragma region methods 
Core::PrimitiveType::Boolean Core::FieldInfo::IsPublic() const
{
	return flags & BindingFlags::Public; 
}

Core::PrimitiveType::Boolean Core::FieldInfo::IsPrivate() const
{
	return flags & BindingFlags::Private;
}

Core::PrimitiveType::Boolean Core::FieldInfo::IsStatic() const
{
	return flags & BindingFlags::Static;
}

Core::PrimitiveType::Boolean Core::FieldInfo::IsConst() const
{
	return flags & BindingFlags::Const;
}

Core::PrimitiveType::FString Core::FieldInfo::Name() const
{
	return name; 
}

Core::BindingFlags Core::FieldInfo::Flags() const
{
	return flags;
}

Core::object Core::FieldInfo::ReflectedObject() const
{
	return reflectedObject; 
}
Core::PrimitiveType::FString Core::FieldInfo::ToString() const
{
	return name;
}
Core::Object& Core::FieldInfo::operator=(const Object* obj)
{
	*reflectedObject = obj; 
	return *this; 
}
#pragma endregion methods 