#include "Utils.h"
#include <Windows.h>


#pragma region methods
void Utils::Log(const std::string& _msg)
{
	std::cout << _msg << std::endl;
}

void Utils::Log(const Object& _obj)
{
	std::cout << _obj.ToString() << std::endl;
}

void Utils::Log(const Object* _obj)
{
	std::cout << _obj->ToString() << std::endl;
}

void Utils::LogError(const std::string& _msg)
{
	const HANDLE _handle = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(_handle, 125); 
	
}

void Utils::LogError(const Object& _msg)
{

}

void Utils::LogError(const Object* _msg)
{
}

#pragma endregion methods
#pragma region override
std::string Utils::ToString() const
{
	return "";
}
#pragma endregion override