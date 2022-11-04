#include <iostream>
#include "Manager/CommandManager.h"
#include "Command/CLS/ClsCommand.h"
#include "Command/CD/CdCommand.h"
#include "Utils/Utils.h"
#include <windows.h>

int main()
{
    SetConsoleTitle(L"Command Prompt"); 
    CommandManager::Instance()->Register(new ClsCommand());
    CommandManager::Instance()->Register(new CdCommand());
    std::string _command = "", _label = "";;
    std::cout << "Microsoft Windows [version" + Utils::GetWindowsVersion() + "]" << std::endl; 
    std::cout << "(c) Microsoft Corporation. All rights reserved" << std::endl << std::endl; 
    while (true)
    {
        std::cout << CdCommand::CurrentPath << '>'; 
        std::getline(std::cin, _command);
        if (_command == "") continue; 
        std::vector<std::string> _arguments = Utils::GetArguments(_command, _label);
        CommandManager::Instance()->ExecuteCommand(_label, _arguments); 
    }
}
