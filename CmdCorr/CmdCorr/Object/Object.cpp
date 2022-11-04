#include "Object.h"
#include <typeinfo>

std::string Object::ToString() const
{
	return typeid(*this).name(); 
}
