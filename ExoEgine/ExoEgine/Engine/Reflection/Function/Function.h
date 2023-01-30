#pragma once
#include "../../Utils/Interface/Log/ILogger.h"
#include <string>
#include <vector>


namespace Engine
{
	namespace PrimaryType
	{
		class String;
	}
	namespace Reflection
	{
		class ParameterInfo;

		class Function : Interface::ILogger
		{
#pragma region f/p
		private:
			std::string name = "";
			std::vector<ParameterInfo*> parameters = std::vector<ParameterInfo*>();
#pragma endregion f/p
#pragma region constructor/destructor
		public:
			Function() = default;
			Function(const std::string& _name, const std::vector<ParameterInfo*>& _parameters);
			virtual ~Function() = default;
#pragma endregion constructor/destructor
#pragma region methods
		public:
			PrimaryType::String ToString() const; 
			class Engine::PrimaryType::String Name() const;
			std::vector<ParameterInfo*> Paramters() const;
#pragma endregion methods
		};
	}
}