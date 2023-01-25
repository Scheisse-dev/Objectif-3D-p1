#pragma once
#include "../../Engine/Object/Object.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Integer/Integer.h"
#include "../../Engine/Reflection/Function/Parameter/ParameterInfo.h"

namespace Test
{
	class ReflectionTest : public Engine::Object
	{
		Engine::PrimaryType::String name = "Toto";
		REGISTER_FIELD(name, &name, BindingFlags::NoPublic)
	public:
		Engine::PrimaryType::Integer age = 24;
		REGISTER_FIELD(age, &age, BindingFlags::Public)

		void Update();
		REGISTER_METHOD(Update, &ReflectionTest::Update, {}, BindingFlags::Public)
		void Display(const std::string& _msg);
		REGISTER_METHOD(Display, &ReflectionTest::Display, (std::vector{new Engine::Reflection::ParameterInfo("msg", 0)}), BindingFlags::Public)

		static void Test();
	};

}