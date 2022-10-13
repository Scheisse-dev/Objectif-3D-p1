#include "StringUtils.h"

std::string StringUtils::Replace(const std::string& _str, const char _old, const char _new)
{
    std::string _result = _str;
    const size_t _size = _result.size(); 
    for (size_t i = 0; i < _size; i++)
    {
        if (_result[i] == _old)
            _result[i] = _new; 
    }
    return _result; 
}

std::string StringUtils::Replace(const std::string& _str, const std::string& _old, const std::string& _new)
{
    std::string _result = _str; 
    size_t _startPos = 0;
    while ((_startPos = _result.find(_old, _startPos)) != std::string::npos)
    {
        _result.replace(_startPos, _old.size(), _new);
        _startPos += _new.size();
    } 
    return _result; 
}
