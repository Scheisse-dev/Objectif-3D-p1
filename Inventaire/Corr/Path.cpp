#include "Path.h"
#include "StringUtils.h"

std::string Path::GetPath(const std::string& _path)
{
    return StringUtils::Replace(_path, '\\', '/'); 
}

std::string Path::Combine(const std::string& _a, const std::string& _b, const std::string& _c)
{
    return _a + '/' + _b + '/' + _c;
}
