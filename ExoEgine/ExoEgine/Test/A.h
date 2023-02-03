#pragma once

#include "../../Engine/PrimaryType/Integer/Integer.h"
#include "../../Engine/PrimaryType/Float/Float.h"
#include "../../Engine/PrimaryType/Double/Double.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Boolean/Boolean.h"
#include "../../Engine/PrimaryType/Vector/Vector2/Vector2.h"
#include "../../Engine/PrimaryType/List/List.h"
#include "B.h"

UCLASS()
class A : public Engine::Object
{
public:
	UPROPERTY() Engine::PrimaryType::Integer age = 50;
REGISTER_FIELD(age, &age, BindingFlags::Public)

UPROPERTY() Engine::PrimaryType::List<Engine::PrimaryType::String> names = { "je", "suis", "une", "loutre", "maritime" };
REGISTER_FIELD(names, &names, BindingFlags::Public)

UPROPERTY() Engine::PrimaryType::List<B*> blist = { new B(), new B(), new B() };
REGISTER_FIELD(blist, &blist, BindingFlags::Public)
//
//Engine::PrimaryType::String ToString() const override
//{
//	Engine::PrimaryType::String _result = "";
//	for (B* _value : blist)
//		_result += _value->toast.ToString();
//	return _result; 
//}
};
