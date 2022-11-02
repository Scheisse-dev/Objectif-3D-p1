#include "MenuItem.h"
#include "Menu.h"

#pragma region constructor/destructor
MenuItem::MenuItem(const std::string _name, Menu* _owner)
{
    name = _name; 
    nextMenu = _owner; 
}

#pragma endregion constructor/destructor
#pragma region methods
std::string MenuItem::Name()
{
    return name; 
}
void MenuItem::OnClick(Menu* _currentMenu)
{
    if (NextMenu == nullptr)
        throw std::exception("Wrong command"); 
    if (!nextMenu -> Equals(_currentMenu))
        nextMenu->SetOldMenu(_currentMenu);
    _currentMenu->Close(); 
    nextMenu->Open(); 
}
Menu* MenuItem::NextMenu() const
{
    return nextMenu; 
}
#pragma endregion methods
#pragma region override
std::string MenuItem::ToString() const
{
    return name + "\n\t";
}
#pragma endregion override