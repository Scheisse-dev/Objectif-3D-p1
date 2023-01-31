#include "FieldInfo.h"


#pragma region constructor
Engine::Reflection::FieldInfo::FieldInfo(PrimaryType::String _name, Object* _reflectedObject, BindingFlags _flags)
{
	name = _name;
	reflectedObject = _reflectedObject;
	flag = _flags;

}


#pragma endregion constructor
#pragma region methods
Engine::PrimaryType::Boolean Engine::Reflection::FieldInfo::IsPublic() const
{
	return  flag & BindingFlags::Public;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldInfo::IsPrivate() const
{
	return  flag & BindingFlags::NoPublic ;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldInfo::IsStatic() const
{
	return flag & BindingFlags::Static;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldInfo::IsArray() const
{
	return flag & BindingFlags::Array;
}
Engine::PrimaryType::Boolean Engine::Reflection::FieldInfo::IsReflectedClass() const
{
	return reflectedObject->IsClass();
}
Engine::PrimaryType::String Engine::Reflection::FieldInfo::Name() const
{
	return name;
}
Engine::Object* Engine::Reflection::FieldInfo::ReflectedObject() const
{
	return reflectedObject;
}
BindingFlags Engine::Reflection::FieldInfo::Flags() const
{
	return flag;
}
Engine::PrimaryType::String Engine::Reflection::FieldInfo::ToString() const
{
	return reflectedObject == nullptr ? PrimaryType::String("nullptr") : reflectedObject->ToString();
}
Engine::Object& Engine::Reflection::FieldInfo::operator=(const Object* obj)
{
	return (*reflectedObject) = obj;
}
#pragma endregion methods