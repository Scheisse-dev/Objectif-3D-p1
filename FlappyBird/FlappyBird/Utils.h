#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

#define color_white 15
#define color_red 4
#define cpmpr_yellow 14

class Utils
{
#pragma region Log
public:
	static inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	static inline COORD cursorPosition = {};
#pragma endregion Log
#pragma region Utils
public:
	static int CinNoBlock();
	void LoadingBar(const std::string& _msg);
	static void SetCursorPosition(const int _x, const int _y);
	static std::string Underline(const std::string& _str);
	static void ClearConsole();
	static void Pause();
	static std::string Separator(const int _count = 10, const char _c = '=');
	//template<typename T>
	//static T UserChoice(const std::string& _msg = "");
#pragma endregion Utils
};/*
template<typename T>
inline T Utils::UserChoice(const std::string& _msg)
{
	if (_msg != "") Log(_msg);
	T _result = T();
	std::cin >> _result;
	return _result;
}*/