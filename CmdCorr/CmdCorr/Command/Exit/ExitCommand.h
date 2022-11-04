#pragma once
#include "../ICommand.h"

class ExitCommand : public ICommand
{
#pragma region constructor/destructor
public: 
	ExitCommand() = default;
	~ExitCommand() override = default; 
#pragma endregion constructor/destructor

#pragma region override
public: 
	 bool Execute(const std::vector<std::string>& _args) override;
	 std::string CommandName() const override;
	 std::string Help() const override;
	 std::string AdvanceHelp() const override;

#pragma endregion override
};

