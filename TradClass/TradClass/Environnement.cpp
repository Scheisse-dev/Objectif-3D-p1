#include "Environnement.h"
#include <windows.h>

std::string Environnement::CurrentDirectory()
{
	TCHAR buffer[MAX_PATH];
	GetCurrentDirectory(_MAX_PATH, buffer); 
	std::wstring _wstring = buffer; 
	_wstring = _wstring.substr(0, _wstring.find_last_of(L"\\/")); // L -> tableau de T char
	return std::string(_wstring.begin(), _wstring.end()); 
}