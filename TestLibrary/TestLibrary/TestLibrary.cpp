
#include "Object.h"
#include <iostream>
#include <FString.h>

using namespace Core;
using namespace PrimitiveType;

int main()
{
	Core::Object* o = new Core::Object();
	Core::PrimitiveType::FString str = "Hello World";
	std::cout << str;
	delete o;
}
