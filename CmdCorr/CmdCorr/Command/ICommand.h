#pragma once

#include "../Object/Object.h"
#include <vector>

class ICommand : public Object
{
#pragma region constructor/destructor
public:
	ICommand() = default;
	~ICommand() override = default;
#pragma endregion constructor/destructor
#pragma region methods
public: 
	virtual bool Execute(const std::vector<std::string>& _args) = 0;
	virtual std::string CommandName() const = 0; 
	virtual std::string Help() const = 0;
	virtual std::string AdvanceHelp() const = 0;
#pragma endregion methods
};
