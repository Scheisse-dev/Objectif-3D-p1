#pragma once
#include <string> 
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <stdio.h>
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
	static void GetWindowsVersion(); 
	static std::string UserChoice();
	static void ClearConsole();
	static void Replace(std::string& _str, const char& _old, const char& _new);
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

inline std::string Utils::UserChoice()
{
	std::string _result = "";
	std::cin >> _result;
	return _result;
}

inline void Utils::GetWindowsVersion()
{
	LPCWSTR lpwstrFilename = L"kernel32.dll";
	DWORD dwVersion = 0;
	DWORD dwMajorVersion = 0;
	DWORD dwMinorVersion = 0;
	DWORD dwBuild = 0;

	NOT_BUILD_WINDOWS_DEPRECATE DWORD GetVersion();

	// Get the Windows version.

	dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
	dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));

	// Get the build number.

	if (dwVersion < 0x80000000)
		dwBuild = (DWORD)(HIWORD(dwVersion));

	printf("Microsoft Windows[Version %d.%d.%d.%d]\n",
		dwMajorVersion,
		dwMinorVersion,
		dwVersion,
		dwBuild);
	std::cout << "(c) Microsoft Corporation. All rights reserved.\n" << std::endl;
}

inline void Utils::ClearConsole()
{
	system("cls"); 
}

inline void Utils::Replace(std::string& _str, const char& _old, const char& _new)
{
	std::ranges::replace(_str, _old, _new); 

}

#pragma endregion Utils