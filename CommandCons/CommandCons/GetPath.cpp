#include "GetPath.h"
#include "Utils.h"
#include <Windows.h>
#include <filesystem>
#include <string>

#pragma region methods
	
#pragma endregion methods


void Path::ValidPath()
{

	std::string _path = std::filesystem::current_path().string();
	Utils::Replace(_path, '\\', '/');
}
