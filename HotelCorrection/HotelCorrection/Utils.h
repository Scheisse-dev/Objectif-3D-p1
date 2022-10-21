#pragma once
#include <string>
#include <iostream>
#include "Object.h"

#define color_white 15
#define color_red 4
#define color_yellow 14

class Utils
{
#pragma region Log
public:
	static void Log(const std::string& _str);
	static void Log(const Object& _obj);
	static void Log(const Object* _obj);
	static void DebugLog(const std::string& _str);
	static void DebugLog(const Object& _obj);
	static void DebugLog(const Object* _obj);
	static void LogWarning(const std::string& _str);
	static void LogWarning(const Object& _obj);
	static void LogWarning(const Object* _obj);
	static void LogError(const std::string& _str);
	static void LogError(const Object& _obj);
	static void LogError(const Object* _obj);

#pragma endregion Log
#pragma region Utils
public:
	template<typename T>
	static T UserChoice(const std::string& _msg = "");
	static std::string UserStringChoice(const std::string& _msg);
	static void LogSeparator(const int _count = 10);
	static std::string Underline(const std::string& _str);
	static void UnderlineAndDisplay(const std::string& _str);
	static void LogTitle(const std::string& _title);
	static void ClearConsole();
	static void Pause();

#pragma endregion Utils
};

template<typename T>
inline T Utils::UserChoice(const std::string& _msg)
{
	if (_msg != "") Log(_msg);
	T _result = T();
	std::cin >> _result;
	std::cin.ignore(1000, '\n');
	return _result;
}
