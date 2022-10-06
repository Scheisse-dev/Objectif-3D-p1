#pragma once
#include <string>

class Example
{
#pragma region f/p
private:
	std::string name = ""; 
	Example* next = nullptr; 
#pragma endregion f/p

#pragma region constructor/destructor
public:
	Example() {
		name = "Thomas"; 
		Test();
	}
	Example(const Example& _copy)
	{
		name = _copy.name;
		next = _copy.next; 
	}
	~Example() {
		delete next; 
		next = nullptr; 
	}
#pragma endregion constructor/destructor

#pragma region methods
public:
	virtual void Test();
#pragma endregion methods
#
#pragma region override
#pragma endregion override

#pragma region operator
	Example operator=(const Example& _other)
	{
		name = _other.name;
		next = _other.next; 
		return *this; 
	}
	bool operator==(const Example& _other)
	{
		return name == _other.name; 
	}
	bool operator!=(const Example& _other)
	{
		return name != _other.name; 
	}
	operator std::string()
	{
		return name; 
	}
	operator bool()
	{
		return name == "toto";
	}
#pragma endregion operator
};

