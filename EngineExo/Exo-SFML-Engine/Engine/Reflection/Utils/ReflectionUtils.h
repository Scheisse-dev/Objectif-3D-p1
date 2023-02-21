#pragma once
#include "../../Object/Object.h"
#include <fstream>

namespace Engine::PrimaryType
{
    class String;
}

namespace Engine::Reflection
{
    class ReflectionUtils
    {
    public:
        static void SerializePrimaryType(std::ostream& _os, const Object* _obj, const Engine::PrimaryType::String& _fieldName);

        static PrimaryType::String GetLine(std::istream& _is, const Engine::PrimaryType::String& _fieldName);
    };
}
