#include "Environnement.h"
#include "FString.h"
#include <ShlObj_core.h>

#pragma warning (disable 4244)


Core::PrimitiveType::FString Core::Environnement::SpecialFolder(const ESpecialFolder& _specialFolder)
{
	TCHAR _buffer[MAX_PATH];
	SHGetSpecialFolderPath(0, _buffer, (int)_specialFolder, false); 
	std::wstring _str = _buffer; 
	return std::string(_str.begin(), _str.end()).c_str();
}
