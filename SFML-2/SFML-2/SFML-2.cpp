#include <iostream>

#include "Core/Input/Input.h"
#include "Core/Manager/Font/FontManager.h"

int main()
{
	Core::Input::Init();
	Core::Manager::FontManager::Instance()->Init();
}
