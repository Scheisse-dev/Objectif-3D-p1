#pragma once
#include <string>
#include <iostream>
#include "..\Object\Object.h"
class Utils : public Object
{
public: 
	void Log(const std::string& _msg);
	void Log(const Object& _msg);
	void Log(const Object* _msg);
	void LogError(const std::string& _msg);
	void LogError(const Object& _msg);
	void LogError(const Object* _msg);

public:
	std::string ToString() const override;
};

