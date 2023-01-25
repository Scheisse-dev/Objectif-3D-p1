#include "Object.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../Utils/DebugMacro.h"
#include "../Reflection/Field/FieldInfo.h"
#include <format>
#include <ranges>

#pragma region constructor/destructor
Engine::Object::Object(const Object& _copy)
{
    flags = _copy.flags;
}

#pragma endregion constructor/destructor
#pragma region methods
Engine::PrimaryType::String Engine::Object::ToString() const
{
    Engine::PrimaryType::String _str = typeid(*this).name();
    _str = _str.Replace("class", "");
    return _str.SubString(_str.FindLastOf(':') + 1).Trim();
}
Engine::PrimaryType::Boolean Engine::Object::IsClass() const
{
    return flags == 0 || !(flags & (int)ClassFlags::Type);
}
int Engine::Object::RegisterClassInfo(int _flags)
{
    return flags = _flags;
}

Engine::Reflection::FieldInfo* Engine::Object::GetField(const PrimaryType::String& _name)
{
    check(fields.contains(_name.ToCstr()), std::format("[Object][Reflection] => {} doesn't exist in fields !", _name), nullptr);
    return dynamic_cast<Reflection::FieldInfo*>(fields[_name.ToCstr()]);
}


size_t Engine::Object::InsertField(const std::string& _name, Object* _var, const BindingFlags& _flags)
{
    check(!fields.contains(_name), std::format("[Object][Reflection] => {} already register in fields", _name), fields.size())
        fields.insert(std::pair(_name, new Reflection::FieldInfo(_name.c_str(), _var, _flags)));
    return fields.size();
}




std::vector<Engine::Reflection::FieldInfo*> Engine::Object::Fields() const 
{
    std::vector<Reflection::FieldInfo*> _result = std::vector<Reflection::FieldInfo*>();
    for (Object* _o : fields | std::ranges::views::values)
    {
        Reflection::FieldInfo* _field = dynamic_cast<Reflection::FieldInfo*>(_o);
        _result.push_back(_field);
    }
    return _result;
}

std::vector<Engine::Reflection::FieldInfo*> Engine::Object::Fields(const BindingFlags& _flags) const
{
    std::vector<Reflection::FieldInfo*> _result = std::vector<Reflection::FieldInfo*>();
    for (Object* _o : fields | std::ranges::views::values)
    {
        Reflection::FieldInfo* _field = dynamic_cast<Reflection::FieldInfo*>(_o);
        if (_field == nullptr) continue;
        if (_field->Flags() & _flags)
            _result.push_back(_field);
    }
    return _result;
}
#pragma endregion methods
#pragma region operator

Engine::Object& Engine::Object::operator=(const Object* _obj)
{
    flags = _obj->flags;
    fields = _obj->fields;
    return *this;
}
#pragma endregion operator