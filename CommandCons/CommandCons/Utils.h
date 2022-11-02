#pragma once
#include <string> 
#include <iostream>
#include "Object.h"


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
	static void LogTitle(const std::string _title); 
#pragma endregion Log

#pragma region Utils
public: 
	template <typename T>
	T UserChoice(const std::string& _msg);
	static void ClearConsole();
#pragma endregion Utils

};



#pragma region Log
inline void Utils::Log(const std::string& _msg)
{
	std::cout << _msg << std::endl; 
}

inline void Utils::Log(const Object& _obj)
{
	std::cout << _obj.ToString() << std::endl; 
}

inline void Utils::Log(const Object* _obj)
{
	std::cout << _obj->ToString() << std::endl;
}

inline void Utils::LogError(const std::string& _msg)
{
	std::cout << _msg << std::endl;
}


inline void Utils::LogError(const Object& _obj)
{
	std::cout << _obj.ToString() << std::endl;
}

inline void Utils::LogError(const Object* _obj)
{
	std::cout << _obj->ToString() << std::endl;
}


inline void Utils::LogTitle(const std::string _title)
{
	std::cout << _title << std::endl; 
}


#pragma endregion Log
#pragma region Utils

template<typename T>
inline T Utils::UserChoice(const std::string& _msg)
{
	if (_msg != "") Log(_msg);
	T _result = T();
	std::cin >> _result;
	return _result;
}

inline void Utils::ClearConsole()
{
	system("cls"); 
}
#pragma endregion Utils