#include "Environment.h"
#include <Windows.h>

std::string Environment::CurrentDirectory()
{
	TCHAR buffer[MAX_PATH];
	GetCurrentDirectory(_MAX_PATH, buffer);
	std::wstring _wstring = buffer;
	_wstring = _wstring.substr(0, _wstring.find_last_of(L"\\/"));
	return std::string(_wstring.begin(), _wstring.end());
}
