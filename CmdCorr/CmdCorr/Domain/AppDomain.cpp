#include "AppDomain.h"


#pragma region methods
std::vector<Object*> AppDomain::GetAssemblies()
{
	std::vector<Object*> _result = std::vector<Object*>(); 
	for (std::pair<const std::string, Object*> _data : classes)
		_result.push_back(_data.second); 
	return _result; 
}

size_t AppDomain::Register(const std::string& _str, Object* _o)
{
	classes.insert(std::pair(_str, _o));
	return classes.size(); 
}



#pragma endregion methods