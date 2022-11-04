#include "TypeCommand.h"
#include "../CD/CdCommand.h"
#include "../../Path/Path.h"
#include "../../IO/File/File.h"
#include <iostream>

bool TypeCommand::Execute(const std::vector<std::string>& _args)
{
	if (_args.empty()) return false;
	std::string _path = _args[0];
	_path = _path.find(':') != std::string::npos ? _path : Path::GetPath(CdCommand::CurrentPath + "/" + _path); 
	if (!File::Exist(_path))
	{
		std::cout << "The system cannot find the file specified" << std::endl << std::endl;
		return true;
	}
	std::cout << File::ReadToEnd(_path);
	return true;
}

std::string TypeCommand::CommandName() const
{
	return "type";
}

std::string TypeCommand::Help() const
{
	return "Displays the contents of a file";
}

std::string TypeCommand::AdvanceHelp() const
{
	return Help() + "\n\nTYPE [DRIVE][path]filename";;
}
