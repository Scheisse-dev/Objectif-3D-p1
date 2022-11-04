#pragma once
#include "../ICommand.h"

class TimeCommand : public ICommand
{
#pragma region override
public: 
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvanceHelp() const override;
#pragma endregion override
};

