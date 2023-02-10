#include "Object.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../Reflection/Fields/FieldsInfo.h"
#include "../Event/Delegate/Delegate.h"
#include "../Utils/DebugMacro.h"
#include <format>
#include <iostream>
#include <ranges>

#pragma region const
Engine::Object::Object(const Object& _copy)
{
    flags = _copy.flags;
}
#pragma endregion

#pragma region methods
Engine::PrimaryType::String Engine::Object::ToString() const
{
    return ClassName();
}

Engine::PrimaryType::String Engine::Object::ClassName() const
{
    PrimaryType::String _str = typeid(*this).name();
    _str = _str.Replace("class", "");
    return _str.SubString(_str.FindLastOf(':') + 1).Trim();
}

Engine::PrimaryType::Boolean Engine::Object::IsClass() const
{
    return flags == 0 || !(flags & (int)ClassFlags::Type);
}

void Engine::Object::Serialize(std::ostream& _os, int _index)
{
    const std::vector<Reflection::FieldsInfo*> _fields = Fields();
    const size_t _length = _fields.size();
    _os << std::string("\"") + ClassName().ToCstr() + "\" : {\n";
    for (size_t i = 0; i < _length; i++)
    {
        _os << std::string(_index, '\t');
        if (_fields[i]->ReflectedObject() == nullptr)
            continue;
        if (_fields[i]->IsReflectedClass())
            _fields[i]->ReflectedObject()->Serialize(_os, _index);
        else
            _fields[i]->ReflectedObject()->SerializeField(_os, _fields[i]->Name(), _index);
        if (i < _length - 1)
            _os << ",\n";
    }
    _os << "\n" + std::string(_index - 1, '\t') + "}";
}

void Engine::Object::DeSerialize(std::istream& _is)
{
    const std::vector<Reflection::FieldsInfo*> _fields = Fields();
    const size_t _length = _fields.size();
    for (size_t i = 0; i < _length; i++)
    {
        if (_fields[i]->ReflectedObject() == nullptr)
            continue;
        if (_fields[i]->IsReflectedClass())
            _fields[i]->ReflectedObject()->DeSerialize(_is);
        else
            _fields[i]->ReflectedObject()->DeSerializeField(_is, _fields[i]->Name());
    }
    OnDeSerialiseFinish();
}

void Engine::Object::SerializeField(std::ostream& _os, const PrimaryType::String& _fieldname, int _index)
{}

void Engine::Object::DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldname)
{}

Engine::Reflection::FieldsInfo* Engine::Object::GetField(const PrimaryType::String& _name)
{
    check(fields.contains(_name.ToCstr()), std::format("[Object][Refelction] => {} doesn't exist in fields", _name), nullptr)
        return  dynamic_cast<Reflection::FieldsInfo*>(fields[_name.ToCstr()]);
}

std::vector<Engine::Reflection::FieldsInfo*> Engine::Object::Fields() const
{
    std::vector<Reflection::FieldsInfo*> _res = std::vector<Reflection::FieldsInfo*>();
    for (Object* _item : fields | std::ranges::views::values)
    {
        Reflection::FieldsInfo* _field = dynamic_cast<Reflection::FieldsInfo*>(_item);
        if (_field == nullptr)
            continue;
        _res.push_back(_field);
    }
    return _res;
}

std::vector<Engine::Reflection::FieldsInfo*> Engine::Object::Fields(const BindingFlags& _flags)
{
    std::vector<Reflection::FieldsInfo*> _res = std::vector<Reflection::FieldsInfo*>();
    for (Object* _item : fields | std::ranges::views::values)
    {
        Reflection::FieldsInfo* _field = dynamic_cast<Reflection::FieldsInfo*>(_item);
        if (_field == nullptr)
            continue;
        if (_field->Flags() & _flags)
            _res.push_back(_field);
    }
    return _res;
}

int Engine::Object::RegisterClassInfo(int _flags)
{
    return flags = _flags;
}

size_t Engine::Object::InsertField(const std::string& _name, Object* _var, const BindingFlags& _flags)
{
    check(!fields.contains(_name), std::format("[Object][Refelction] => {} alraedy register in fields", _name), fields.size())
        fields.insert(std::pair(_name, new Reflection::FieldsInfo(_name.c_str(), _var, _flags)));
    return fields.size();
}
#pragma endregion

#pragma region operator
Engine::Object& Engine::Object::operator=(const Object* _obj)
{
    flags = _obj->flags;
    fields = _obj->fields;
    return *this;
}
#pragma endregion

