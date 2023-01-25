#pragma once
#include "../../Engine/Object/Object.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Integer/Integer.h"
#include "../../Engine/Reflection/Function/Parameter/ParameterInfo.h"


	class A : public Engine::Object
	{
		UPROPERTY() Engine::PrimaryType::String name = "Toto";
	public:
		UPROPERTY() Engine::PrimaryType::Integer age = 24;

		UFUNCTION() void Update();

		UFUNCTION() void Display(const std::string& _msg);

		static void Test();
	};
