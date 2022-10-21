#include "Client.h"
#include <format>

#pragma region constructor
Client::Client(const std::string& _first, const std::string& _last, const int _age)
{
	firstName = _first;
	lastName = _last;
	age = _age;
}

Client::Client(const Client& _copy)
{
	firstName = _copy.firstName;
	lastName = _copy.lastName;
	age = _copy.age;
}
#pragma endregion constructor
#pragma region methods
std::string Client::FirstName() const
{
	return firstName;
}

std::string Client::LastName() const
{
	return lastName;
}

int Client::Age() const
{
	return age;
}
#pragma endregion methods
#pragma region override
std::string Client::ToString() const
{
	return std::format("first name: {}\nlast name: {}\nage: {}", firstName, lastName, age);
}
#pragma endregion override