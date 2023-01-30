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
	public:
		Engine::PrimaryType::Integer age = 24;
		void Update();
		void Display(const std::string& _msg);

		static void Test();
	};

}
