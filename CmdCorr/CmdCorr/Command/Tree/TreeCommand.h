#pragma once
#include "../ICommand.h"

class TreeCommand : public ICommand
{
#pragma region methods 
private:
	void RecursiveDirectory(const std::string& _path, int _index); 
#pragma endregion methods
#pragma region override
public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName() const override;
	virtual std::string Help() const override;
	virtual std::string AdvanceHelp() const override;
#pragma endregion override
};

