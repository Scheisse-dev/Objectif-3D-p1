#pragma once
#include <map>

namespace Engine
{
	class Object;
}

namespace Test
{
}

#define REGISTER_TYPE(type) const size_t Type##type = TypeOfData::Register(#type, new type());

#define GET_TYPE(name) return TypeOfData::Types(name);

struct TypeOfData
{
	static inline std::map<std::string, Engine::Object*> Types = std::map<std::string, Engine::Object*>();

	static size_t Register(std::string typeName, Engine::Object* type)
	{
		if (Types.contains(typeName)) return Types.size();
		Types.insert(std::pair(typeName, type));
		return Types.size();
	}
};

template<typename T>
struct TypeOf
{

	static T* GetType(T _type)
	{
		return nullptr;
	}

};


#define Expose_TypeOf(type)\
template<>\
struct TypeOf<type> \
{\
	static type* GetType()\
	{\
		return TypeOfData::Types[#type];\
	}\
};\
if (TypeOfData::Types.contains(#type)) return; \
TypeOfData::Types.insert(std::pair(#type, new type())); \

