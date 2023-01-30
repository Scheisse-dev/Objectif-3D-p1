#pragma once
#include "../../Engine/Object/Object.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Integer/Integer.h"
#include "../../Engine/Reflection/Function/Parameter/ParameterInfo.h"


UCLASS()
class A : public Engine::Object
{

public: 

public:
	UFUNCTION() void Update();
REGISTER_METHOD(Update, &A::Update, {}, BindingFlags::Public)

	UFUNCTION() void Display(std::string& _msg, int _machin);
REGISTER_METHOD(Display, &A::Display, (std::vector<Engine::Reflection::ParameterInfo*>{new Engine::Reflection::ParameterInfo("_msg", 0),new Engine::Reflection::ParameterInfo("_machin", 1)}), BindingFlags::Public)

	UFUNCTION() void Test(); 
REGISTER_METHOD(Test, &A::Test, {}, BindingFlags::Public)

};
