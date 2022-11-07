#pragma once
#include <map>
#include <vector>
#include <string>

class Object; 

#define REGISTER_CLASS(type)size_t datasize##type = AppDomain::Register(#type, new type());


class AppDomain
{
#pragma region f/p
private: 
	static inline std::map<std::string, Object*> classes = std::map<std::string, Object*>(); 
#pragma endregion f/p
#pragma region methods
public: 
	static std::vector<Object*> GetAssemblies(); 
	static size_t Register(const std::string& _str, Object* _o);
	template <typename T>
	static std::vector<T*> GetAssembliesOf(); 
#pragma endregion methods

};

template<typename T>
inline std::vector<T*> AppDomain::GetAssembliesOf()
{
	std::vector<T*> _result = std::vector<T*>();
	for (std::pair<const std::string, Object*> _data : classes)
	{
		T* _class = dynamic_cast<T*> (_data.second);
		if (_class == nullptr) continue;
		_result.push_back(_class);
	}
	return _result;
}
