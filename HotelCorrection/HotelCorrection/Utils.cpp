#include "Utils.h"
#include <windows.h>

#define DEBUG

#pragma region Log
void Utils::Log(const std::string& _str)
{
	std::cout << _str << std::endl;
}

void Utils::Log(const Object& _obj)
{
	std::cout << _obj.ToString() << std::endl;
}

void Utils::Log(const Object* _obj)
{
	std::cout << _obj->ToString() << std::endl;
}

void Utils::DebugLog(const std::string& _str)
{
#ifdef DEBUG
	std::cout << "[LOG] => " << _str << std::endl;
#endif
}

void Utils::DebugLog(const Object& _obj)
{
#ifdef DEBUG
	std::cout << "[LOG] => " << _obj.ToString() << std::endl;
#endif
}

void Utils::DebugLog(const Object* _obj)
{
#ifdef DEBUG
	std::cout << "[LOG] => " << _obj->ToString() << std::endl;
#endif
}

void Utils::LogWarning(const std::string& _str)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_yellow);
	std::cout << "[WARNING] => " << _str << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}

void Utils::LogWarning(const Object& _obj)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_yellow);
	std::cout << "[WARNING] => " << _obj.ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}

void Utils::LogWarning(const Object* _obj)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_yellow);
	std::cout << "[WARNING] => " << _obj->ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}

void Utils::LogError(const std::string& _str)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _str << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}
void Utils::LogError(const Object& _obj)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _obj.ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}
void Utils::LogError(const Object* _obj)
{
#ifdef DEBUG
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_handle, color_red);
	std::cout << "[ERROR] => " << _obj->ToString() << std::endl;
	SetConsoleTextAttribute(_handle, color_white);
#endif
}
std::string Utils::UserStringChoice(const std::string& _msg)
{
	if (_msg != "") Log(_msg);
	std::string _result = "";
	std::getline(std::cin, _result);
	std::cin.ignore(1000, '\n');
	return _result;
}
void Utils::LogSeparator(const int _count)
{
	Log(std::string(_count, '='));
}

std::string Utils::Underline(const std::string& _str)
{
	int _tabCount = 0, _count = 0;
	for (char _c : _str)
	{
		if (_c == '\t')
		{
			_tabCount++;
			continue;
		}
		_count++;
	}
	return std::string(_tabCount, '\t') + std::string(_count, '-');
}
void Utils::UnderlineAndDisplay(const std::string& _str)
{
	Log(_str);
	Log(Underline(_str));
}
void Utils::LogTitle(const std::string& _title)
{
	UnderlineAndDisplay("\t\t" + _title);
}
void Utils::ClearConsole()
{
	system("cls");
}
void Utils::Pause()
{
	system("pause");
}
#pragma endregion Log