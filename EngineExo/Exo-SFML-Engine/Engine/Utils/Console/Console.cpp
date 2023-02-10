#include "Console.h"
#include "../../PrimaryType/String/String.h"
#include <iostream>

#pragma region methods
void Engine::Utils::Console::Log(const std::string& _msg)
{
	std::cout << "[Log] => " << _msg << std::endl;
}

void Engine::Utils::Console::Log(const Object& _obj)
{
	std::cout << "[Log] => " << _obj.ToString() << std::endl;
}

void Engine::Utils::Console::Log(const ILogger* _obj)
{
	std::cout << "[Log] => " << _obj->ToString() << std::endl;
}

void Engine::Utils::Console::LogWarning(const std::string& _msg)
{
	SetConsoleTextAttribute(consoleHandle, COLOR_YELLOW);
	std::cout << "[Log Warning] => " << _msg << std::endl;
	SetConsoleTextAttribute(consoleHandle, COLOR_WHITE);
}

void Engine::Utils::Console::LogWarning(const Object& _obj)
{
	SetConsoleTextAttribute(consoleHandle, COLOR_YELLOW);
	std::cout << "[Log Warning] => " << _obj.ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, COLOR_WHITE);
}

void Engine::Utils::Console::LogWarning(const ILogger* _obj)
{
	SetConsoleTextAttribute(consoleHandle, COLOR_YELLOW);
	std::cout << "[Log Warning] => " << _obj->ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, COLOR_WHITE);
}

void Engine::Utils::Console::LogError(const std::string& _msg)
{
	SetConsoleTextAttribute(consoleHandle, COLOR_RED);
	std::cout << "[Log Error] => " << _msg << std::endl;
	SetConsoleTextAttribute(consoleHandle, COLOR_WHITE);
}

void Engine::Utils::Console::LogError(const Object& _obj)
{
	SetConsoleTextAttribute(consoleHandle, COLOR_RED);
	std::cout << "[Log Error] => " << _obj.ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, COLOR_WHITE);
}

void Engine::Utils::Console::LogError(const ILogger* _obj)
{
	SetConsoleTextAttribute(consoleHandle, COLOR_RED);
	std::cout << "[Log Erro] => " << _obj->ToString() << std::endl;
	SetConsoleTextAttribute(consoleHandle, COLOR_WHITE);
}

#pragma endregion
