#include "MenuItem.h"
#include "Menu.h"

#pragma region constructor/destructor
MenuItem::MenuItem(const std::string& _name, const std::string& _description, Menu* _owner)
{
    name = _name;
    description = _description;
    nextMenu = _owner;
}

MenuItem::MenuItem(const MenuItem& _copy)
{
    name = _copy.name;
    description = _copy.description;
    nextMenu = _copy.nextMenu;
}
#pragma endregion constructor/destructor
#pragma region methods
void MenuItem::OnClick(Menu* _currentMenu)
{
    if (nextMenu == nullptr)
        throw std::exception("[MenuItem] => next menu is null !");
    if (!nextMenu->Equals(_currentMenu))
        nextMenu->SetOldMenu(_currentMenu);
    _currentMenu->Close();
    nextMenu->Open();
}
std::string MenuItem::Name() const
{
    return name;
}

std::string MenuItem::Description() const
{
    return description;
}

Menu* MenuItem::NextMenu() const
{
    return nextMenu;
}
#pragma endregion methods
#pragma region override
std::string MenuItem::ToString() const
{
    return name + "\n\t-> " + description;
}
#pragma endregion override