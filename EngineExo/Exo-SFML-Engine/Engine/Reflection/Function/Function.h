#pragma once
#include <string>
#include <vector>
#include "../../Utils/Interface/Log/ILogger.h"

namespace Engine::PrimaryType
{
    class String;
}

namespace Engine::Reflection
{
    class ParameterInfo;

    class Function : public Interface::ILogger
    {
#pragma region var
    private:
        std::string name = "";
        std::vector<ParameterInfo*> parameters = std::vector<ParameterInfo*>();
#pragma endregion
#pragma region const/dest
    public:
        Function() = default;
        Function(const std::string& _name, const std::vector<ParameterInfo*>& _parameters);
        virtual ~Function() = default;
#pragma endregion
#pragma region methods
    public:
        PrimaryType::String Name() const;
        std::vector<ParameterInfo*> Parameters() const;
#pragma endregion
#pragma region override
    public:
        PrimaryType::String ToString() const override;
#pragma endregion
    };
}

