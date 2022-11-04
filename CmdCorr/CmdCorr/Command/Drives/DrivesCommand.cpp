#include "DrivesCommand.h"
#include <Windows.h>
#include <iostream>

bool DrivesCommand::Execute(const std::vector<std::string>& _args)
{
	if (_args.size() != 0) return false;
	char* _drives = new char[MAX_PATH];
	if (GetLogicalDriveStringsA(MAX_PATH, _drives))
	{
		for (int i = 0; i < 100; i += 4)
		{
			if (_drives[i] != (char)0 && _drives[i] != (char)-51)
				std::cout << std::string{ _drives[i], _drives[i + 1], _drives[i + 3] } << std::endl;
		}
	}
	else return false;
	return true;
}

std::string DrivesCommand::CommandName() const
{
	return "drives";
}

std::string DrivesCommand::Help() const
{
	return "display all drives in the computer";
}

std::string DrivesCommand::AdvanceHelp() const
{
	return Help() + "\n\nDRIvES";
}
