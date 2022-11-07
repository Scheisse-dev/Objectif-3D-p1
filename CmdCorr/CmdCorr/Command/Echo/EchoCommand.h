#pragma once
#include "../ICommand.h"

UCLASS()
class EchoCommand : public ICommand
{
#pragma region f/p
private: 
	bool isOn = true;
#pragma endregion f/p
#pragma region constructor/destructor
public: 
	EchoCommand() = default;
	~EchoCommand() override = default;
#pragma endregion constructor/destructor
#pragma region methods
public: 
	bool Execute(const std::vector<std::string>& _args) override ;
	 std::string CommandName()  const override ;
	 std::string Help() const override ;
	std::string AdvanceHelp() const override ;
#pragma endregion methods
};

