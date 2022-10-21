#include "StringUtils.h"

std::vector<std::string> StringUtils::Split(const std::string& _str, const char _c)
{
    std::vector<std::string> _result = std::vector<std::string>();
    std::string _string = _str;
    size_t _pos = 0;
    while ((_pos = _string.find(_c)) != std::string::npos)
    {
        _result.push_back(_string.substr(0, _pos));
        _string = _string.erase(0, _pos + 1);
    }
    _result.push_back(_string.substr(0, _pos));
    return _result;
}

std::string StringUtils::Replace(const std::string& _str, const std::string& _old, const std::string& _new)
{
    std::string _result = _str;
    size_t _pos = 0;
    while ((_pos = _result.find(_old, _pos)) != std::string::npos)
    {
        _result.replace(_pos, _old.size(), _new);
        _pos += _new.size();
    }
    return _result;
}
