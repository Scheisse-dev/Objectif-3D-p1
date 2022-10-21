#pragma once
#include "Menu.h"
class ReservationMenu : public Menu
{
#pragma region constructor
public:
	ReservationMenu();
#pragma endregion constructor
#pragma region override
public:
	void Open() override;
#pragma endregion override
};

