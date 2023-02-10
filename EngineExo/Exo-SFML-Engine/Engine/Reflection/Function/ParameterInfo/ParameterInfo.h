#pragma once
#include <string>
#include "../../../Utils/Interface/Log/ILogger.h"

namespace Engine::Reflection
{
    class ParameterInfo : public Interface::ILogger
    {
#pragma region var
    private:
        std::string name = "";
        int position = -1;
#pragma endregion
#pragma region const/dest
    public:
        ParameterInfo() = default;
        ParameterInfo(const std::string& _name, int _position);
        ~ParameterInfo() = default;
#pragma endregion
#pragma region methods
    public:
        std::string Name() const;
        int Position() const;
        PrimaryType::String ToString() const override;
#pragma endregion
    };
}
