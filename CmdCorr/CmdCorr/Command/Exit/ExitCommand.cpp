#include "ExitCommand.h"

bool ExitCommand::Execute(const std::vector<std::string>& _args)
{
	int _exitCode = 0;
	try
	{
		if(!_args.empty())
		_exitCode = !_args.empty() ? std::stoi(_args[0]) : 0;
	}
	catch (const std::exception&)
	{
		_exitCode = -1;
	}
	
	exit(_exitCode);
	return true;
}

std::string ExitCommand::CommandName() const
{
	return "exit";
}

std::string ExitCommand::Help() const
{
	return "Quits the cmd.exe program (command interpreter)";
}

std::string ExitCommand::AdvanceHelp() const
{
	std::string _result = "EXIT [eitcode]\n\n";
	_result += "\texitCode specifies a numeric number, sets the process exit code with that number";
	return _result; 

}
