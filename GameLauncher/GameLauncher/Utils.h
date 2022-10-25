#pragma once
#include <string>
#include <iostream>
class Object;

#define color_white 15
#define color_red 4

class Utils
{
#pragma region Log
public:
	static void Log(const std::string& _msg);
	static void Log(const Object& _obj);
	static void Log(const Object* _obj);
	static void LogError(const std::string& _msg);
	static void LogError(const Object& _obj);
	static void LogError(const Object* _obj);
	static void LogTitle(const std::string& _title);
	static void LoadingBar(const std::string& _msg);
#pragma endregion Log
#pragma region Utils
public:
	static std::string Underline(const std::string& _str);
	static void ClearConsole();
	static void Pause();
	static std::string Separator(const int _count = 10, const char _c = '=');
	template<typename T>
	static T UserChoice(const std::string& _msg = "");
	template<typename T>
	static T UserChoice(const std::string& _msg, const T& _defaultValue, const T& _a, const T& _b);
#pragma endregion Utils

};

template<typename T>
inline T Utils::UserChoice(const std::string& _msg)
{
	if (_msg != "") Log(_msg);
	T _result = T();
	std::cin >> _result;
	return _result;
}

template<typename T>
inline T Utils::UserChoice(const std::string& _msg, const T& _defaultValue, const T& _a, const T& _b)
{
	if (_msg != "") Log(_msg);
	T _result = _defaultValue;
	while (_result != _a && _result != _b)
		std::cin >> _result;
	return _result;
}
