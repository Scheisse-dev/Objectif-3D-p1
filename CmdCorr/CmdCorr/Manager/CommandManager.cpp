#include "CommandManager.h"
#include "../Command/ICommand.h"
#include <format>
#include <iostream>
#include <iomanip>


#pragma region methods
void CommandManager::DisplayAllHelp() const
{
	std::cout << " ------------HELP--------------" << std::endl;
	for (std::pair<const std::string, ICommand*> _command : commands)
	{
		if (_command.first == "" || _command.second == nullptr) continue;
		std::cout << std::setw(10) << std::right << _command.first << "\t\t" << _command.second->Help() << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
}
void CommandManager::DisplayHelp(const std::string& _label)
{
	if (!commands.contains(_label))
	{
		DisplayNotRecognized(_label);
		return;
	}
	std::cout << "---------------------" << std::endl;
}
void CommandManager::Register(ICommand* _command)
{
	const std::string& _commandName = _command->CommandName();
	if (commands.contains(_commandName))
		throw std::exception(std::format("[Command Manager] => {} already exist !", _commandName).c_str());
	commands.insert(std::pair(_commandName, _command));
}

void CommandManager::Register(const std::initializer_list<ICommand*>& _commands)
{
	for (ICommand* _command : _commands)
		Register(_command); 
}

void CommandManager::ExecuteCommand(const std::string& _label, const std::vector<std::string>& _args)
{
	if (!commands.contains(_label))
	{
		DisplayNotRecognized(_label);
		return;
	}
	ICommand* _command = commands[_label];
	if (!_command->Execute(_args))std::cout << _command->Help() << std::endl;
	else std::cout << std::endl << std::endl; 

}
void CommandManager::DisplayNotRecognized(const std::string& _label)
{
	std::cout << "\'" << _label << "\'" << "is not recognized as an internal command" << std::endl;
}
#pragma endregion methods