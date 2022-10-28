#pragma once
#include "Object.h"
#include <source_location>
#include <string>
#include <format>

class Exception : public Object
{
private:
	std::string error = " ";

public: 
	Exception(const std::source_location& _location )
	{
		std::string _filename = _location.file_name();
		_filename = _filename.substr(_filename.find_last_of('\\') + 1); 
		error = std::format("{} in class {} in function {} at line {}", "error", _filename, _location.function_name(), _location.line());
	}
	Exception(const std::string& _error, const std::source_location& _location)
	{
		std::string _filename = _location.file_name();
		_filename = _filename.substr(_filename.find_last_of('\\') + 1);
		error = std::format("{} in class {} in function {} at line {}", _error, _filename, _location.function_name(), _location.line());
	}

public:
	std::string ToString() const override
	{
		return error;
	}
};

