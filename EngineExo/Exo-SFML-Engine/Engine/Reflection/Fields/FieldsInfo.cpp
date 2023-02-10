#include "FieldsInfo.h"
#include "../../Object/Object.h"
#include "../../PrimaryType/ValueType/ValueType.h"

#pragma region const
Engine::Reflection::FieldsInfo::FieldsInfo(const PrimaryType::String& _name, Object* _reflected, BindingFlags _flags)
{
    name = _name;
    reflectedObject = _reflected;
    flags = _flags;
}

Engine::Reflection::FieldsInfo::FieldsInfo(const FieldsInfo& _copy)
{
    name = _copy.name;
    reflectedObject = _copy.reflectedObject;
    flags = _copy.flags;
}
#pragma endregion


#pragma region methods
const char* Engine::Reflection::FieldsInfo::Name() const
{
    return name;
}

Engine::Object* Engine::Reflection::FieldsInfo::ReflectedObject() const
{
    return reflectedObject;
}

BindingFlags Engine::Reflection::FieldsInfo::Flags() const
{
    return flags;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldsInfo::IsReflectedClass()
{
    return reflectedObject->IsClass();
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldsInfo::IsPublic()
{
    return flags & BindingFlags::Public;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldsInfo::IsPrivate()
{
    return flags & BindingFlags::NoPublic;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldsInfo::IsStatic()
{
    return flags & BindingFlags::Static;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldsInfo::IsArray()
{
    return flags & BindingFlags::Array;
}
#pragma endregion

#pragma region override
Engine::PrimaryType::String Engine::Reflection::FieldsInfo::ToString() const
{
    return reflectedObject == nullptr ? "nullptr" : reflectedObject->ToString().ToCstr();
}
#pragma endregion

#pragma region operator
Engine::Object& Engine::Reflection::FieldsInfo::operator=(const Object* _obj)
{
    return (*reflectedObject) = _obj;
}
#pragma endregion

