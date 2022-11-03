#include "SettingManager.h"
#include "Utils.h";
#include <string>

void SettingManager::OnEcho()
{
	std::string _str = Utils::UserChoice();
	for (int i = 0; i < _str.size(); i++)
		tolower(_str[i]);
	if (_str == "disable")
		echo = false;
	else if (_str == "enable")
		echo = true;	
}
