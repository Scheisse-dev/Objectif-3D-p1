#pragma once
#include "../../Engine/Object/Object.h"


UCLASS()
class B : public Engine::Object
{
public:
	UPROPERTY() Engine::PrimaryType::List<Engine::PrimaryType::Integer> toast = { 7,8,9,10 };
REGISTER_FIELD(toast, &toast, BindingFlags::Public)
};

