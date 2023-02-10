#pragma once
#include "../../Object/Object.h"
#include "../../Utils/Interface/Log/ILogger.h"
#include <Windows.h>

namespace Engine::Utils
{
#define COLOR_RED 4
#define COLOR_YELLOW 14
#define COLOR_WHITE 15

	class Console : public Object
	{
		DECLARE_CLASS_INFO(Console, Object)
#pragma region var
	private:
		static const inline HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#pragma endregion
#pragma region methods
	public:
		static void Log(const std::string& _msg);
		static void Log(const Object& _msg);
		static void Log(const ILogger* _msg);

        static void LogWarning(const std::string& _msg);
        static void LogWarning(const Object& _msg);
        static void LogWarning(const ILogger* _msg);

        static void LogError(const std::string& _msg);
        static void LogError(const Object& _msg);
        static void LogError(const ILogger* _msg);
#pragma endregion

	};

}

