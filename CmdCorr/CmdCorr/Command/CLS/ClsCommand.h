#pragma once
#include "../ICommand.h"

UCLASS()
class ClsCommand : public ICommand
{
#pragma region constructor/destructor
public: 
	ClsCommand() = default;
	~ClsCommand() = default; 
#pragma endregion constructor/destructor
#pragma region methods 
public: 
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvanceHelp() const override;
#pragma endregion methods
};

