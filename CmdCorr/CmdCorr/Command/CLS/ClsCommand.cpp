#include "ClsCommand.h"

bool ClsCommand::Execute(const std::vector<std::string>& _args)
{
    system("cls");
    return true; 
}

std::string ClsCommand::CommandName() const
{
    return "cls";
}

std::string ClsCommand::Help() const
{
    return "Clears the screen";
}

std::string ClsCommand::AdvanceHelp() const
{
    return Help() + "\n\nCLS";
}
