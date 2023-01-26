#pragma once
#include "../../Engine/Object/Object.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Integer/Integer.h"
#include "../../Engine/Reflection/Function/Parameter/ParameterInfo.h"


	class A : public Engine::Object
	{
		UPROPERTY() Engine::PrimaryType::String name = "Toto";
REGISTER_FIELD(name, &name, BindingFlags::NoPublic)

	public:
		UPROPERTY() Engine::PrimaryType::Integer age = 24;
REGISTER_FIELD(age, &age, BindingFlags::Public)
	private:
		UPROPERTY() Engine::PrimaryType::Integer* Life = new Engine::PrimaryType::Integer(0);
REGISTER_FIELD(Life, Life, BindingFlags::NoPublic)


	public:	
		UFUNCTION() void Update();
		REGISTER_METHOD(Update, &Update, (std::vector{ new Engine::Reflection::ParameterInfo() }), BindingFlags::Public)


		UFUNCTION() void Display(std::string& _msg, int _machin);
		REGISTER_METHOD(Display, &Display, (std::vector{ new Engine::Reflection::ParameterInfo("_msg", 0), new Engine::Reflection::ParameterInfo("_machin", 1) }), BindingFlags::Public)
	private:
		UFUNCTION() void Test();
REGISTER_METHOD(Test, &Test,(std::vector{ new Engine::Reflection::ParameterInfo() }) ,BindingFlags::NoPublic)
	};
