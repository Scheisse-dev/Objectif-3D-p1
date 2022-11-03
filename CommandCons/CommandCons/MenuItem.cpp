#include "MenuItem.h"
#include "Menu.h"


#pragma region methods
std::string MenuItem::Name()
{
    return name; 
}

#pragma endregion methods
#pragma region override
std::string MenuItem::ToString() const
{
    return name + "\n\t";
}
#pragma endregion override