#include "EchoCommand.h"
#include <iostream>

bool EchoCommand::Execute(const std::vector<std::string>& _args)
{
	if (_args.size() == 0)
	{
		std::cout << "ECHO is " << (isOn ? "on" : "off") << "." << std::endl;
		return true;
	}

	const std::string& _first = _args[0];
	if (_first == "on") isOn = true;
	else if (_first == "off") isOn = false; 
	else if (isOn)
	{
		for (const std::string& _str : _args)
			std::cout << _str << " ";
	}
	return true;

}

std::string EchoCommand::CommandName() const
{
	return "echo";
}

std::string EchoCommand::Help() const
{
	return "displays messages, or turns command-echoing on or off";
}

std::string EchoCommand::AdvanceHelp() const
{
	std::string _result = "Displays messages, or turns command-echoing on or off.\n\n";
	_result += "  ECHO [ON | OFF]\n";
	_result += "  ECHO [messages]\n\n";
	_result += "Type ECHO without parameters to display the current echo setting.";
	return _result;
}
