#pragma once
#include "../ICommand.h"

UCLASS()
class DrivesCommand : public ICommand
{
	
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvanceHelp() const override;
};

