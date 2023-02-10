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
        UPROPERTY() Engine::PrimaryType::Integer integer = 42;
REGISTER_FIELD(integer, &integer, BindingFlags::NoPublic)
            UPROPERTY() Engine::PrimaryType::Double doubl = 3.14;
REGISTER_FIELD(doubl, &doubl, BindingFlags::NoPublic)
            UPROPERTY() Engine::PrimaryType::Float floate = 6.9f;
REGISTER_FIELD(floate, &floate, BindingFlags::NoPublic)
            UPROPERTY() Engine::PrimaryType::String str = "string";
REGISTER_FIELD(str, &str, BindingFlags::NoPublic)
            UPROPERTY() Engine::PrimaryType::Boolean boolean = true;
REGISTER_FIELD(boolean, &boolean, BindingFlags::NoPublic)
            UPROPERTY() Engine::PrimaryType::Vector2 vector = Engine::PrimaryType::Vector2(0, 0);
REGISTER_FIELD(vector, &vector, BindingFlags::NoPublic)
            UPROPERTY() Engine::PrimaryType::List<Engine::Component*> list = Engine::PrimaryType::List<Engine::Component*>({ new Engine::Transform() , new Test::PlayerComponent()});
REGISTER_FIELD(list, &list, BindingFlags::NoPublic)
    };
}
