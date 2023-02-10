#include "Function.h"
#include "../../PrimaryType/String/String.h"

#pragma region const
Engine::Reflection::Function::Function(const std::string& _name, const std::vector<ParameterInfo*>& _parameters)
{
    name = _name;
    parameters = _parameters;
}
#pragma endregion

#pragma region methods
Engine::PrimaryType::String Engine::Reflection::Function::Name() const
{
    return name.c_str();
}

std::vector<Engine::Reflection::ParameterInfo*> Engine::Reflection::Function::Parameters() const
{
    return parameters;
}
#pragma endregion

#pragma region override
Engine::PrimaryType::String Engine::Reflection::Function::ToString() const
{
    std::string _res = "Name: " + name + "\n";
    for (const ParameterInfo* _param : parameters)
    {
        _res += _param->ToString();
        _res += " ";
    }
    return _res.c_str();
}
#pragma endregion