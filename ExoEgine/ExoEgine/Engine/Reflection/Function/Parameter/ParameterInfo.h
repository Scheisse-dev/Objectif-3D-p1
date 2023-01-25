#pragma once
#include <string>
#include "../../../Object/Object.h"


namespace Engine::Reflection
{
	class ParameterInfo : public Object
	{
#pragma region f/p
	private:
		std::string name = ""; 
		int position = 0;
#pragma endregion f/p
#pragma region constructor
	public:
		ParameterInfo() = default;
		ParameterInfo(std::string _name, int _position);
		~ParameterInfo() = default;
#pragma endregion constructor
#pragma region methods
	public:
		std::string Name() const;
		int Position() const;
#pragma endregion methods
	};

}