#include "CdCommand.h"
#include "../../Path/Path.h"
#include "../../Utils/String/StringUtils.h"
#include "../../IO/Directory/Directory.h"
#include <shlobj_core.h>
#include <iostream>

#pragma region methods
std::string CdCommand::GetProfileFolder()
{
	TCHAR _buffer[_MAX_PATH]; 
	SHGetSpecialFolderPath(0, _buffer, 0x0028, false);
	std::wstring _result = _buffer; 
	return std::string(_result.begin(), _result.end()); 
}

#pragma endregion methods

#pragma region override
bool CdCommand::Execute(const std::vector<std::string>& _args)
{
	if (_args.size() == 0)
	{
		std::cout << CurrentPath;
		return true;
	}
	std::string _path = Path::GetPath(_args[0]); 
	if (_path == "..")
	{
		CurrentPath = Path::GetParentDirectory(CurrentPath);
		return true; 
	}
	if (!StringUtils::Contains(_path, '/'))
	{
		_path = Path::Combine({ CurrentPath, _path });
	}
	if (!Directory::DirectoryExist(_path))
	{
		std::cout << "The specified path cannot be found";
		return true;
	}
	CurrentPath = _path;
	return true;
}

std::string CdCommand::CommandName() const
{
	return "cd";
}

std::string CdCommand::Help() const
{
	return "Display the name of or changes the current directory.";
}
std::string CdCommand::AdvanceHelp() const
{
	std::string _result = "Displays the name of or the current directory.\n\n";
	_result += "CD [drive:][path]\n";
	_result += "CD ..\n\n";
	_result += "   ..  Specifies that you want to change to the parent directory.\n\n";
	_result += "Type cd only to display the current directory";
	return _result;
}
#pragma endregion override
