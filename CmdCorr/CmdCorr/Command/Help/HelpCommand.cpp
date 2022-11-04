#include "HelpCommand.h"
#include "../../Manager/CommandManager.h"

bool HelpCommand::Execute(const std::vector<std::string>& _args)
{
	if (_args.empty())
	{
		CommandManager::Instance()->DisplayAllHelp();
		return true;
	}
	CommandManager::Instance()->DisplayHelp(_args[0]);
	return true;
}

std::string HelpCommand::CommandName() const
{
	return "help";
}

std::string HelpCommand::Help() const
{
	return "Provides help information for windows commands.";
}

std::string HelpCommand::AdvanceHelp() const
{
	std::string _result = Help() + "\n\n";
	_result += "HELP [command]\n\n";
	return _result;
}
