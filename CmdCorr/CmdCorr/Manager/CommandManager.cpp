#include "CommandManager.h"
#include "../Command/ICommand.h"
#include <format>
#include <iostream>


#pragma region methods
void CommandManager::Register(ICommand* _command)
{
	const std::string& _commandName = _command->CommandName();
	if (commands.contains(_commandName))
		throw std::exception(std::format("[Command Manager] => {} already exist !", _commandName).c_str());
	commands.insert(std::pair(_commandName, _command));
}

void CommandManager::ExecuteCommand(const std::string& _label, const std::vector<std::string>& _args)
{
	if (!commands.contains(_label))
	{
		std::cout << "\'" << _label << "\'" << "is not recognized as an internal command" << std::endl; 
		return;
	}
	ICommand* _command = commands[_label];
	if (!_command->Execute(_args))std::cout << _command->Help() << std::endl;
	else std::cout << std::endl << std::endl; 

}
#pragma endregion methods