#include <iostream>
#include "Manager/CommandManager.h"
#include "Command/CLS/ClsCommand.h"
#include "Command/CD/CdCommand.h"
#include "Command/Echo/EchoCommand.h"
#include "Command/Exit/ExitCommand.h"
#include "Command/TaskList/TaskListCommand.h"
#include "Command/Tree/TreeCommand.h"
#include "Command/Drives/DrivesCommand.h"
#include "Command/Type/TypeCommand.h"
#include "Command/Time/TimeCommand.h"
#include "Command/Help/HelpCommand.h"
#include "Utils/Utils.h"
#include <windows.h>

int main()
{
    SetConsoleTitle(L"Command Prompt"); 
    CommandManager::Instance()->Register({
        new ClsCommand(),
        new CdCommand(),
        new EchoCommand(),
        new ExitCommand(),
        new TaskListCommand(),
        new TreeCommand(),
        new DrivesCommand(),
        new TimeCommand(),
        new TypeCommand(),
        new HelpCommand()
        });
   
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
