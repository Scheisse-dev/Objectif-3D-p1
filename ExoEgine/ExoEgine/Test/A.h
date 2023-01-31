#pragma once

#include "../../Engine/PrimaryType/Integer/Integer.h"
#include "../../Engine/PrimaryType/Float/Float.h"
#include "../../Engine/PrimaryType/Double/Double.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Boolean/Boolean.h"

UCLASS()
class A : public Engine::Object
{
	UPROPERTY() Engine::PrimaryType::Integer age = 0;
REGISTER_FIELD(age, &age, BindingFlags::NoPublic)

		UPROPERTY() Engine::PrimaryType::Float fo = 0.0f;
REGISTER_FIELD(fo, &fo, BindingFlags::NoPublic)

UPROPERTY() Engine::PrimaryType::Double doudouble = 10000000000000000000;
REGISTER_FIELD(doudouble, &doudouble, BindingFlags::NoPublic)

UPROPERTY() Engine::PrimaryType::String stream = "string";
REGISTER_FIELD(stream, &stream, BindingFlags::NoPublic)


UPROPERTY() Engine::PrimaryType::Boolean boogie = true; 
REGISTER_FIELD(boogie, &boogie, BindingFlags::NoPublic)
};
