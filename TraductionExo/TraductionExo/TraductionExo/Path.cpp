#include "Path.h"
#include "StringUtils.h"

std::string Path::Combine(const std::string& _a, const std::string& _b)
{
	return GetPath(_a + DirectorySeparatorChar + _b);
}

std::string Path::Combine(const std::string& _a, const std::string& _b, const std::string& _c)
{
	return GetPath(_a + DirectorySeparatorChar + _b + DirectorySeparatorChar + _c);
}

std::string Path::GetPath(const std::string& _path)
{
	std::string _result = _path;
	StringUtils::Replace(_result, '\\', '/');
	return _result;
}

std::string Path::GetDirectoryPath(const std::string& _path)
{
	const std::string _result = GetPath(_path);
	const int _index = _result.find_last_of('/');
	return _result.substr(0, _index);
}
