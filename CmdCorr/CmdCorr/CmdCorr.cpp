#include "Manager/CommandManager.h"
#include "Utils/Utils.h"
#include "Assembly.h"
#include <windows.h>
#include <iostream>

int main()
{
    SetConsoleTitle(L"Command Prompt"); 

    for (ICommand* _command : AppDomain::GetAssembliesOf<ICommand>())
    {
        CommandManager::Instance()->Register(_command); 
    }
   
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
