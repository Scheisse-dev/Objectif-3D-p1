#pragma once
#include <string>
#include "Object.h"

class IGame : public Object
{
#pragma region destructor
public:
	virtual ~IGame() = default; 
#pragma endregion destructor
#pragma region methods
public:
	virtual void OnStart() = 0; 
	virtual void OnUptdate() = 0; 
	virtual void OnEnd() = 0; 
	virtual void DisplayMenu() = 0; 
	virtual std::string GameName() const = 0; 
	virtual std::string GameDescription() const = 0;
#pragma endregion methods
};

