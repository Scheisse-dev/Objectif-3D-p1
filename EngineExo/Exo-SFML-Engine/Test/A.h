#pragma once
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/Double/Double.h"
#include "../Engine/PrimaryType/Float/Float.h"
#include "../Engine/PrimaryType/String/String.h"
#include "../Engine/PrimaryType/Boolean/Boolean.h"
#include "../Engine/PrimaryType/Vector2/Vector2.h"
#include "../Engine/PrimaryType/List/List.h"
#include "../Engine/Transform/Transform.h" 
#include "Component/PlayerComponent.h"

namespace Test
{
    UCLASS()
        class A : public Engine::Object
    {
    private:
        UPROPERTY() Engine::PrimaryType::Boolean ball = false;
REGISTER_FIELD(ball, &ball, BindingFlags::NoPublic)
    };
}
