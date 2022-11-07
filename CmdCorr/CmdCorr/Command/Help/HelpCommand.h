#pragma once
#include "../ICommand.h"

UCLASS()
class HelpCommand: public ICommand
{
public: 
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvanceHelp() const override;
};

