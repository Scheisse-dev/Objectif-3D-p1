#include "StringUtils.h"
#include <algorithm>

void StringUtils::Replace(std::string& _str, const char& _old, const char& _newValue)
{
	std::ranges::replace(_str, _old, _newValue);
}
