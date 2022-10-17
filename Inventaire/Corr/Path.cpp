#include "Path.h"
#include "StringUtils.h"

std::string Path::GetPath(const std::string& _path)
{
    return StringUtils::Replace(_path, '\\', '/'); 
}
std::string Path::Combine(const std::string& _a, const std::string& _b)
{
    return _a + '/' + _b;
}
std::string Path::Combine(const std::string& _a, const std::string& _b, const std::string& _c)
{
    return _a + '/' + _b + '/' + _c;
}

std::string Path::GetFileNameWithoutExtension(const std::string& _path)
{
    std::string _result = GetPath(_path); 
    _result = _result.substr(_result.find_last_of('/') + 1);
    _result = _result.substr(_result.find_last_of('.')); 
    return _result; 
}


