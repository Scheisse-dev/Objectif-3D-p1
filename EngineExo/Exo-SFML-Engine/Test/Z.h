#pragma once
#include "../Engine/Object/Object.h"
#include "../Engine/Utils/DebugMacro.h"
#include "../Engine/PrimaryType/String/String.h"
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/Boolean/Boolean.h"
//inherited object

namespace Test
{
    UCLASS();
    class Z : public Engine::Object
    {
#pragma region f.p
    private:
        UPROPERTY() Engine::PrimaryType::String strong = "string";
REGISTER_FIELD(strong, &strong, BindingFlags::NoPublic)
        UPROPERTY() Engine::PrimaryType::Integer pint = 1;
REGISTER_FIELD(pint, &pint, BindingFlags::NoPublic)
        UPROPERTY() Engine::PrimaryType::Boolean ball = false;
REGISTER_FIELD(ball, &ball, BindingFlags::NoPublic)
#pragma endregion
#pragma region const
    public:
        Z() = default;
#pragma endregion
#pragma region meth
    public:
        Engine::PrimaryType::String Strong()
        {
            return strong;
        }
        Engine::PrimaryType::Integer Pint()
        {
            return pint; 
        }
        Engine::PrimaryType::Boolean Ball()
        {
            return ball;
        }
#pragma endregion
    };

}
