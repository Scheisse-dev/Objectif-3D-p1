#pragma once
#include "../Exception/Exception.h"
#include "Console/Console.h"

#define LOG(msg) Engine::Utils::Console::Log(msg);
#define LOG_WARNING(msg) Engine::Utils::Console::LogWarning(msg);
#define LOG_ERROR(msg) Engine::Utils::Console::LogError(msg);

#define checkLow(condition, msg)\
	if(!condition)\
	{\
		Engine::Utils::Console::LogError(msg);\
		return;\
	}

#define check(condition, msg, result)\
	if(!condition)\
	{\
		Engine::Utils::Console::LogError(msg);\
		return result;\
	}

#define checkBaseOf(a, b)\
	if constexpr(std::is_base_of_v<a, b>)\
	{\
		Engine::Utils::Console::LogError(#b "must be inherited of " #a);\
		return;\
	}
