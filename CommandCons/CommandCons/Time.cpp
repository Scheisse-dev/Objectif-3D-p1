#include "Time.h"
#include "Utils.h"
#include <format>
#include <ctime>

#pragma warning(disable : 4996)

#pragma region methods

void Time::NowInternal()
{
	time_t timetoday;
	time(&timetoday);
	std::cout << asctime(localtime(&timetoday));
}


#pragma endregion methods






