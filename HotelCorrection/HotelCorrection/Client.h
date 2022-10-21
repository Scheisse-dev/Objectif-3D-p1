#pragma once
#include "Object.h"

class Client : public Object
{
#pragma region f/p
private:
	std::string firstName = "";
	std::string lastName = "";
	int age = 0;
#pragma endregion f/p
#pragma region constructor
public:
	Client() = default;
	Client(const std::string& _first, const std::string& _last, const int _age);
	Client(const Client& _copy);
#pragma endregion constructor
#pragma region methods
public:
	std::string FirstName() const;
	std::string LastName() const;
	int Age() const;
#pragma endregion methods
#pragma region override
public:
	std::string ToString() const;
#pragma endregion override
};