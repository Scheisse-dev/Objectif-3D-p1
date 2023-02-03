#pragma once
#include "../Engine/Object/Object.h"
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/List/List.h"
#include "B.h"

UCLASS()
class C : public Engine::Object
{
	UPROPERTY() Engine::PrimaryType::List<Engine::PrimaryType::Integer> test = { 1,2,3,4,5};
REGISTER_FIELD(test, &test, BindingFlags::NoPublic)

	UPROPERTY()	B lul = B();
REGISTER_FIELD(lul, &lul, BindingFlags::NoPublic)

};

