#include "Utils.h"
#include <Windows.h>
#include <vector>
#include <format>
#include "String/StringUtils.h"

std::string Utils::GetWindowsVersion()
{
	const wchar_t* _system = L"kernel32.dll";
	DWORD _dummy = {};
	const DWORD _info = GetFileVersionInfoSizeExW(FILE_VER_GET_NEUTRAL, _system, &_dummy);
	std::vector<char> _buffer(_info);
	GetFileVersionInfoExW(FILE_VER_GET_NEUTRAL, _system, _dummy, _info, _buffer.data());
	void* _p = nullptr; 
	UINT _size = 0;
	VerQueryValueW(_buffer.data(), L"\\", &_p, &_size);
	const VS_FIXEDFILEINFO* _fileInfo = static_cast<const VS_FIXEDFILEINFO*>(_p);
	if (_fileInfo == nullptr)
		throw std::exception("[Utils] => error on get windows version !"); 
	return std::format("{}.{}.{}.{}", 
		std::to_string(HIWORD(_fileInfo->dwFileVersionMS)), 
		std::to_string(LOWORD(_fileInfo->dwFileVersionMS)),
		std::to_string(HIWORD(_fileInfo->dwFileVersionLS)),
		std::to_string(LOWORD(_fileInfo->dwFileVersionLS)));
}

std::vector<std::string> Utils::GetArguments(const std::string& _command, std::string& _commandLabel)
{
	std::vector<std::string> _parsed = StringUtils::Split(_command, ' ');
	std::vector<std::string> _result = std::vector<std::string>();
	_commandLabel = _parsed[0];
	const size_t _size = _parsed.size();
	for (size_t i = 1; i < _size; i++)
		_result.push_back(_parsed[i]);


	return _result;
}
