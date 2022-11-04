#include "TimeCommand.h"
#include <ctime>
#include <iostream>
#pragma warning(disable : 4996)

#pragma region override
bool TimeCommand::Execute(const std::vector<std::string>& _args)
{
	time_t _now = time(nullptr);
	tm _timeStruct = *localtime(&_now);
	char _buffer[80];
	strftime(_buffer, sizeof(_buffer), "%X", &_timeStruct);
	std::cout << "The current time is: " << _buffer;
	return false;
}

std::string TimeCommand::CommandName() const
{
	return "time";
}

std::string TimeCommand::Help() const
{
	return "Displays the system time.";
}

std::string TimeCommand::AdvanceHelp() const
{
	return Help() + "\n\nTIME";
}
#pragma endregion override